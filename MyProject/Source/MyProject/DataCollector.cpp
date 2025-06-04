#include "DataCollector.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "FlagActor.h"
#include "AProjectileClass.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/HUD.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "InferenceClientHelper.h"

TArray<float> ADataCollector::SendInputToModel(const TArray<float>& InputData)
{
    TArray<float> Output;

    if (InputData.Num() == 0)
    {
        return Output;
    }

    if (!ModelSocket || !bSocketConnected)
    {
        return Output;
    }

    int32 BytesSent = 0;
    ModelSocket->Send((uint8*)InputData.GetData(), InputData.Num() * sizeof(float), BytesSent);

    TArray<uint8> RecvBuffer;
    RecvBuffer.SetNum(7 * sizeof(float));
    int32 BytesRead = 0;

    if (ModelSocket->Wait(ESocketWaitConditions::WaitForRead, FTimespan::FromMilliseconds(10)))
    {
        ModelSocket->Recv(RecvBuffer.GetData(), RecvBuffer.Num(), BytesRead);

        if (BytesRead == 7 * sizeof(float))
        {
            float* FloatData = reinterpret_cast<float*>(RecvBuffer.GetData());
            for (int i = 0; i < 7; ++i)
            {
                Output.Add(FloatData[i]);
            }
        }
    }

    return Output;
}

ADataCollector::ADataCollector()
{
    PrimaryActorTick.bCanEverTick = true;
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    ModelSocket = nullptr;
    bSocketConnected = false;
}

static InferenceClientHelper* GInferenceClient = nullptr;

void ADataCollector::BeginPlay()
{
    Super::BeginPlay();

    UE_LOG(LogTemp, Warning, TEXT("BeginPlay"));

    FIPv4Address IP(127, 0, 0, 1);
    int32 Port = (InferenceModelType == "Reward") ? 5006 : 5005;
    UsedPort = (InferenceModelType == "Reward") ? 5006 : 5005;

    ModelSocket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("ModelSocket"), false);
    TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
    Addr->SetIp(IP.Value);
    Addr->SetPort(Port);

    bSocketConnected = ModelSocket->Connect(*Addr);

    if (!GInferenceClient)
    {
        GInferenceClient = new InferenceClientHelper();

        bool bSuccess = GInferenceClient->Connect();
    }

    LastKnownP1Position = FVector(-1.0f, -1.0f, -1.0f);
    LastKnownP1Rotation = FRotator(-1.0f, -1.0f, -1.0f);

    LastKnownFlagStates.Init(0, Flags.Num());

    UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFlagActor::StaticClass(), Flags);

    Flags.Sort([](const AActor& A, const AActor& B) {
        const FVector& LocA = A.GetActorLocation();
    const FVector& LocB = B.GetActorLocation();

    if (FMath::IsNearlyEqual(LocA.X, LocB.X, 1.0f))
    {
        return LocA.Y < LocB.Y;
    }
    return LocA.X < LocB.X;
        });

    FlagStates.Init(0, Flags.Num());
    LastKnownOwners.Init(0, Flags.Num());
    LastKnownFlagStates.Init(0, Flags.Num());
    ActualFlagStates.Init(0, Flags.Num());

    for (int32 i = 0; i < Flags.Num(); ++i)
    {
        AFlagActor* Flag = Cast<AFlagActor>(Flags[i]);
        if (!Flag) continue;

        LastKnownOwners[i] = Flag->OwnerPlayer;

        if (i == 0 || i == 1)
        {
            FlagStates[i] = 1;
        }
        else if (i == 2 || i == 3)
        {
            FlagStates[i] = 2;
        }
        else
        {
            FlagStates[i] = 0;
        }
        LastKnownFlagStates[i] = FlagStates[i];
    }

    GameTimer = 180.0f;
    bIsGameActive = true;
}


void ADataCollector::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (bGameEnded)
    {
        return;
    }

    float CurrentTime = GetWorld()->GetTimeSeconds();

    if (bIsGameActive)
    {
        GameTimer -= DeltaTime;

        P1Flags = 0;
        P2Flags = 0;

        for (int32 i = 0; i < ActualFlagStates.Num(); ++i)
        {
            if (ActualFlagStates[i] == 0) P1Flags++;
            if (ActualFlagStates[i] == 1) P2Flags++;
        }

        if (GameTimer <= 0.0f && !bGameEnded)
        {
            GameTimer = 0.0f;
            bIsGameActive = false;
            bGameEnded = true;

            if (P1Flags > P2Flags)
            {
                UE_LOG(LogTemp, Warning, TEXT("P1 vyhral"));
            }
            else if (P2Flags > P1Flags)
            {
                UE_LOG(LogTemp, Warning, TEXT("P2 vyhral"));
            }
            else if (P2Flags == P1Flags){
                UE_LOG(LogTemp, Warning, TEXT("Remiza"));
            }

            UE_LOG(LogTemp, Warning, TEXT("Cas vyprsal, zacinam ukladat data do CSV suboru.."));
        }
    }

    if (!bGameEnded)
    {
        if (!Player1)
        {
            Player1 = UGameplayStatics::GetPlayerCharacter(this, 0);
            if (!Player1)
            {
                return;
            }
        }

        if (!Player2)
        {
            Player2 = UGameplayStatics::GetPlayerCharacter(this, 1);
            if (!Player2)
            {
                return;
            }
        }

        APlayerController* P2Controller = Cast<APlayerController>(Player1->GetController());
        APlayerController* P1Controller = Cast<APlayerController>(Player1->GetController());

        if (!Player1 || !Player2 || !P2Controller || !P1Controller) {
            P1Flags = 0;
            P2Flags = 0;

            for (int32 i = 0; i < ActualFlagStates.Num(); ++i)
            {
                if (ActualFlagStates[i] == 0) P1Flags++;
                if (ActualFlagStates[i] == 1) P2Flags++;
            }

            if (P1Flags > P2Flags) {
                bIsGameActive = false;
                bGameEnded = true;
                UE_LOG(LogTemp, Warning, TEXT("Vyhral hrac P1, obsadil vsetky vlajky."));
            }
            else if (P2Flags > P1Flags) {
                bIsGameActive = false;
                bGameEnded = true;
                UE_LOG(LogTemp, Warning, TEXT("Vyhral hrac P2, obsadil vsetky vlajky."));
            }
            UE_LOG(LogTemp, Warning, TEXT("Casovac dosiahol hodnotu nula. Zacina proces ukladania dat."));

            bDataSavingStarted = true;

            SaveData();

            return;
        }

        int32 RoundedGameTimer = FMath::RoundToInt(GameTimer);

        for (int32 i = 0; i < Flags.Num(); ++i)
        {
            AFlagActor* Flag = Cast<AFlagActor>(Flags[i]);
            if (Flag)
            {
                FVector FlagLocation = Flag->GetActorLocation();
                float DistanceToFlag = FVector::Dist(Player2Position, FlagLocation);
            }
        }

        if (!bP2InputEnabled)
        {
            if (P2Controller)
            {
                Player2->EnableInput(P2Controller);
                FInputModeGameOnly InputMode;
                P2Controller->SetInputMode(InputMode);
                P2Controller->bShowMouseCursor = false;

                bP2InputEnabled = true;
            }
        }

        Player1Position = Player1->GetActorLocation();
        Player1Rotation = Player1->GetActorRotation();
        Player2Position = Player2->GetActorLocation();
        Player2Rotation = Player2->GetActorRotation();

        FHitResult HitResult;
        FCollisionQueryParams TraceParams(FName(TEXT("VisionTrace")), true, Player2);
        TraceParams.bTraceComplex = true;
        TraceParams.bReturnPhysicalMaterial = false;

        bool bHit = GetWorld()->LineTraceSingleByChannel(
            HitResult,
            Player2Position + FVector(0, 0, 50),
            Player1Position + FVector(0, 0, 50),
            ECC_Visibility,
            TraceParams
        );

        if (bHit && HitResult.GetActor() == Player1)
        {
            bP2SeesP1 = true;
            LastKnownP1Position = Player1Position;
            LastKnownP1Rotation = Player1Rotation;
        }
        else
        {
            bP2SeesP1 = false;
        }

        if (P1Controller && bP2SeesP1)
        {
            bP1WPressed = P1Controller->IsInputKeyDown(EKeys::W);
            bP1APressed = P1Controller->IsInputKeyDown(EKeys::A);
            bP1SPressed = P1Controller->IsInputKeyDown(EKeys::S);
            bP1DPressed = P1Controller->IsInputKeyDown(EKeys::D);
            bP1QPressed = P1Controller->IsInputKeyDown(EKeys::Q);
            bP1EPressed = P1Controller->IsInputKeyDown(EKeys::E);
            bP1SpacePressed = P1Controller->IsInputKeyDown(EKeys::SpaceBar);
        }
        else
        {
            bP1WPressed = false;
            bP1APressed = false;
            bP1SPressed = false;
            bP1DPressed = false;
            bP1QPressed = false;
            bP1EPressed = false;
            bP1SpacePressed = false;
        }

        if (P2Controller)
        {
            bP2Num4Pressed = P2Controller->IsInputKeyDown(EKeys::NumPadFour);
            bP2Num5Pressed = P2Controller->IsInputKeyDown(EKeys::NumPadFive);
            bP2Num8Pressed = P2Controller->IsInputKeyDown(EKeys::NumPadEight);
            bP2Num6Pressed = P2Controller->IsInputKeyDown(EKeys::NumPadSix);
            bP2Num7Pressed = P2Controller->IsInputKeyDown(EKeys::NumPadSeven);
            bP2Num9Pressed = P2Controller->IsInputKeyDown(EKeys::NumPadNine);
            bP2PlusPressed = P2Controller->IsInputKeyDown(EKeys::Add);
        }

        if (P1Controller->IsInputKeyDown(EKeys::SpaceBar))
        {
            if (!bP1SpacePrevState && (CurrentTime - SpaceBarCooldown >= InputCooldownTime))
            {
                bP1SpacePressed = true;
                SpaceBarCooldown = CurrentTime;
            }
            else
            {
                bP1SpacePressed = false;
            }
        }
        else
        {
            bP1SpacePressed = false;
        }

        if (P2Controller->IsInputKeyDown(EKeys::Add))
        {
            if (!bP2PlusPrevState && (CurrentTime - NumpadPlusCooldown >= InputCooldownTime))
            {
                bP2PlusPressed = true;
                NumpadPlusCooldown = CurrentTime;
            }
            else
            {
                bP2PlusPressed = false;
            }
        }
        else
        {
            bP2PlusPressed = false;
        }

        bP1SpacePrevState = P1Controller->IsInputKeyDown(EKeys::SpaceBar);
        bP2PlusPrevState = P2Controller->IsInputKeyDown(EKeys::Add);

        for (int32 i = 0; i < Flags.Num(); ++i)
        {
            AFlagActor* Flag = Cast<AFlagActor>(Flags[i]);
            if (!Flag) continue;

            FVector FlagLocation = Flag->GetActorLocation();

            FHitResult Hit;
            FCollisionQueryParams Params;
            Params.AddIgnoredActor(Player2);

            bool bCanSee = GetWorld()->LineTraceSingleByChannel(
                Hit,
                Player2Position + FVector(0, 0, 50),
                FlagLocation + FVector(0, 0, 50),
                ECC_Visibility,
                Params
            );

            if (bCanSee && Hit.GetActor() == Flag)
            {
                int32 SeenOwner = Flag->OwnerPlayer + 1;

                if (FlagStates[i] != SeenOwner)
                {
                    LastKnownFlagStates[i] = FlagStates[i];
                    FlagStates[i] = SeenOwner;
                }
            }
        }

        for (int32 i = 0; i < Flags.Num(); ++i)
        {
            AFlagActor* Flag = Cast<AFlagActor>(Flags[i]);
            if (!Flag) continue;

            int32 CurrentOwner = Flag->OwnerPlayer;

            if (ActualFlagStates[i] != CurrentOwner)
            {
                ActualFlagStates[i] = CurrentOwner;
            }
        }

        TArray<float> ProjectileInfo;

        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAProjectileClass::StaticClass(), ActiveProjectiles);

        TArray<AActor*> ProjectilesToForget;

        for (const auto& Elem : ProjectileTTL)
        {
            AActor* Projectile = Elem.Key;
            float TTL = Elem.Value;

            if (!IsValid(Projectile) || CurrentTime >= TTL)
            {
                ProjectilesToForget.Add(Projectile);
            }
        }

        for (AActor* Projectile : ProjectilesToForget)
        {
            ProjectileTTL.Remove(Projectile);
            LastKnownProjectilePositions.Remove(Projectile);
        }

        for (AActor* Projectile : ActiveProjectiles)
        {
            if (!IsValid(Projectile)) continue;

            APawn* InstigatorPawn = Cast<APawn>(Projectile->GetInstigator());
            if (!InstigatorPawn) continue;

            if (!ProjectileOwnerMap.Contains(Projectile))
            {
                int32 OwnerValue = (InstigatorPawn == Player1) ? 1 : 2;
                ProjectileOwnerMap.Add(Projectile, OwnerValue);
            }

            FHitResult Hit;
            FCollisionQueryParams Params;
            Params.AddIgnoredActor(Player2);

            bool bCanSee = GetWorld()->LineTraceSingleByChannel(
                Hit,
                Player2Position + FVector(0, 0, 50),
                Projectile->GetActorLocation() + FVector(0, 0, 10),
                ECC_Visibility,
                Params
            );

            if (bCanSee && Hit.GetActor() == Projectile)
            {
                LastKnownProjectilePositions.FindOrAdd(Projectile) = Projectile->GetActorLocation();
                CurrentlyVisibleProjectiles.Add(Projectile);
            }
            else if (!LastKnownProjectilePositions.Contains(Projectile))
            {
                LastKnownProjectilePositions.Add(Projectile, Projectile->GetActorLocation());
            }
            if (!ProjectileTTL.Contains(Projectile))
            {
                ProjectileTTL.Add(Projectile, CurrentTime + 5.0f);
            }
        }

        ActiveProjectiles.Empty();

        FString FlagLog = "FlagStates (P2 view): ";
        for (int32 i = 0; i < FlagStates.Num(); ++i)
        {
            FString StateString = "UNK";
            if (FlagStates[i] == 1) StateString = "P1";
            else if (FlagStates[i] == 2) StateString = "P2";
            else if (FlagStates[i] == 0) StateString = "??";
            else if (FlagStates[i] == -1) StateString = "--";

            FString LastKnown = "UNK";
            if (LastKnownFlagStates[i] == 1) LastKnown = "P1";
            else if (LastKnownFlagStates[i] == 2) LastKnown = "P2";
            else if (LastKnownFlagStates[i] == 0) LastKnown = "??";

            FlagLog += FString::Printf(TEXT("F%d:[%s|Last:%s] "), i, *StateString, *LastKnown);
        }
        UE_LOG(LogTemp, Warning, TEXT("%s"), *FlagLog);

        for (const auto& Elem : LastKnownProjectilePositions)
        {
            if (ProjectileTTL.Contains(Elem.Key))
            {
                float RemainingTime = ProjectileTTL[Elem.Key] - CurrentTime;
                if (RemainingTime > 0)
                {
                    UE_LOG(LogTemp, Warning, TEXT("X=%.0f Y=%.0f | TTL: %.2f"),
                        Elem.Value.X, Elem.Value.Y, RemainingTime);
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("X=%.0f Y=%.0f | Seen now"),
                    Elem.Value.X, Elem.Value.Y);
            }
        }

        FVector Directions[8] = {
        FVector(1, 0, 0), FVector(1, 1, 0).GetSafeNormal(), FVector(0, 1, 0), FVector(-1, 1, 0).GetSafeNormal(),
        FVector(-1, 0, 0), FVector(-1, -1, 0).GetSafeNormal(), FVector(0, -1, 0), FVector(1, -1, 0).GetSafeNormal()
        };
        float TraceDistance = 500.0f;
        for (int i = 0; i < 8; ++i)
        {
            FVector Start = Player2Position + FVector(0, 0, 50);
            FVector End = Start + Directions[i] * TraceDistance;

            FHitResult WallHit;
            bool bWall = GetWorld()->LineTraceSingleByChannel(
                WallHit,
                Start,
                End,
                ECC_Visibility,
                TraceParams
            );

            bWallsDetected[i] = bWall;
        }

        if (bFirstTick)
        {
            bFirstTick = false;
        }

        TArray<float> TickRow;

        TickRow.Add(FMath::RoundToInt(GameTimer));

        for (int32 i = 0; i < Flags.Num(); ++i)
        {
            AFlagActor* Flag = Cast<AFlagActor>(Flags[i]);
            if (Flag)
            {
                FVector FlagLocation = Flag->GetActorLocation();
                float Distance = FVector::Dist(Player2Position, FlagLocation);
                TickRow.Add(Distance);
            }
        }

        for (int32 i = 0; i < Flags.Num(); ++i)
        {
            AFlagActor* Flag = Cast<AFlagActor>(Flags[i]);
            if (Flag)
            {
                FVector FlagLocation = Flag->GetActorLocation();
                TickRow.Add(FlagLocation.X);
                TickRow.Add(FlagLocation.Y);
            }
        }

        TickRow.Add(bP2SeesP1 ? 1.0f : 0.0f);

        TickRow.Add(Player2Position.X);
        TickRow.Add(Player2Position.Y);
        TickRow.Add(Player2Rotation.Yaw);

        TickRow.Add(bP2Num4Pressed ? 1.0f : 0.0f);
        TickRow.Add(bP2Num5Pressed ? 1.0f : 0.0f);
        TickRow.Add(bP2Num8Pressed ? 1.0f : 0.0f);
        TickRow.Add(bP2Num6Pressed ? 1.0f : 0.0f);
        TickRow.Add(bP2Num7Pressed ? 1.0f : 0.0f);
        TickRow.Add(bP2Num9Pressed ? 1.0f : 0.0f);
        TickRow.Add(bP2PlusPressed ? 1.0f : 0.0f);

        if (bP2SeesP1)
        {
            TickRow.Add(Player1Position.X);
            TickRow.Add(Player1Position.Y);
            TickRow.Add(Player1Rotation.Yaw);

            TickRow.Add(bP1WPressed ? 1.0f : 0.0f);
            TickRow.Add(bP1APressed ? 1.0f : 0.0f);
            TickRow.Add(bP1SPressed ? 1.0f : 0.0f);
            TickRow.Add(bP1DPressed ? 1.0f : 0.0f);
            TickRow.Add(bP1QPressed ? 1.0f : 0.0f);
            TickRow.Add(bP1EPressed ? 1.0f : 0.0f);
            TickRow.Add(bP1SpacePressed ? 1.0f : 0.0f);
        }
        else
        {
            TickRow.Add(LastKnownP1Position.X);
            TickRow.Add(LastKnownP1Position.Y);
            TickRow.Add(LastKnownP1Rotation.Yaw);

            // 7 inputov nula
            for (int i = 0; i < 7; ++i)
            {
                TickRow.Add(0.0f);
            }
        }

        for (int32 i = 0; i < FlagStates.Num(); ++i)
        {
            TickRow.Add((float)FlagStates[i]);
        }

        // Detekcia stien
        for (int i = 0; i < 8; ++i)
        {
            TickRow.Add(bWallsDetected[i] ? 1.0f : 0.0f);
        }

        for (const auto& Elem : LastKnownProjectilePositions)
        {
            AActor* Projectile = Elem.Key;
            FVector Pos = Elem.Value;

            ProjectileInfo.Add(Pos.X);
            ProjectileInfo.Add(Pos.Y);

            int32 ProjectileOwner = ProjectileOwnerMap.Contains(Projectile) ? ProjectileOwnerMap[Projectile] : -1;
            ProjectileInfo.Add((float)ProjectileOwner);

            float IsVisible = CurrentlyVisibleProjectiles.Contains(Projectile) ? 1.0f : 0.0f;
            ProjectileInfo.Add(IsVisible);

            FString OwnerText = TEXT("Unknown");
            if (ProjectileOwner == 1) OwnerText = TEXT("P1");
            else if (ProjectileOwner == 2) OwnerText = TEXT("P2");

            FString VisibilityText = IsVisible > 0.5f ? TEXT("Visible") : TEXT("Hidden");

            UE_LOG(LogTemp, Warning, TEXT("X=%.0f Y=%.0f | Owner=%s | %s"),
                Pos.X, Pos.Y, *OwnerText, *VisibilityText);
        }

        CollectedTickData.Add(TickRow);
        CollectedFlagCounts.Add(FVector2D(P1Flags, P2Flags));
        CurrentlyVisibleProjectiles.Empty();
        AllProjectileInfo.Add(ProjectileInfo);

        if (bUseAIForP2)
        {
            TArray<float> Inputs = TickRow;
            TArray<float> Outputs = SendInputToModel(Inputs);
            LastModelOutputs = Outputs;

            if (Outputs.Num() != 7)
            {
                return;
            }

            float Threshold = 0.01f;

            if (UsedPort == 5006)
            {
                bP2Num5Pressed = (Outputs[2] > Outputs[0] && Outputs[2] < 0.77f);
                bP2Num8Pressed = (!bP2Num5Pressed && Outputs[0] > Threshold);

                bP2Num4Pressed = (Outputs[1] > Outputs[3] && Outputs[1] > Threshold);
                bP2Num6Pressed = (Outputs[3] > Outputs[1] && Outputs[3] > Threshold);

                bP2Num7Pressed = (Outputs[4] > Outputs[5] && Outputs[4] > 0.40f && Outputs[4] < 0.46f);
                bP2Num9Pressed = (Outputs[5] > Outputs[4] && Outputs[5] > 0.40f && Outputs[5] < 0.46f);

                bP2PlusPressed = Outputs[6] > 0.28f;
            }
            else if (UsedPort == 5005)
            {
                bP2Num8Pressed = (Outputs[0] > Outputs[2] && Outputs[0] > Threshold);
                bP2Num5Pressed = (Outputs[2] > Outputs[0] && Outputs[2] > Threshold);

                bP2Num4Pressed = (Outputs[1] > Outputs[3] && Outputs[1] > Threshold);
                bP2Num6Pressed = (Outputs[3] > Outputs[1] && Outputs[3] > Threshold);

                bP2Num7Pressed = (Outputs[4] > Outputs[5] && Outputs[4] > Threshold);
                bP2Num9Pressed = (Outputs[5] > Outputs[4] && Outputs[5] > Threshold);

                bP2PlusPressed = Outputs[6] > Threshold;
            }

            UE_LOG(LogTemp, Warning, TEXT("AI výstup modelu: [%.2f %.2f %.2f %.2f %.2f %.2f %.2f]"),
                Outputs[0], Outputs[1], Outputs[2], Outputs[3], Outputs[4], Outputs[5], Outputs[6]);

            UE_LOG(LogTemp, Warning, TEXT("Predikované akcie: [4:%d 5:%d 8:%d 6:%d 7:%d 9:%d +:%d]"),
                bP2Num4Pressed, bP2Num5Pressed, bP2Num8Pressed,
                bP2Num6Pressed, bP2Num7Pressed, bP2Num9Pressed, bP2PlusPressed);
        }
    }

    if (bGameEnded && !bDataSavingStarted)
    {
        bDataSavingStarted = true;

        SaveData();

        return;
    }
}

void ADataCollector::GetAIInput(bool& bUp, bool& bDown, bool& bLeft, bool& bRight, bool& bDiagLeft, bool& bDiagRight, bool& bShoot)
{
    bUp = bP2Num8Pressed;
    bDown = bP2Num5Pressed;
    bLeft = bP2Num4Pressed;
    bRight = bP2Num6Pressed;
    bDiagLeft = bP2Num7Pressed;
    bDiagRight = bP2Num9Pressed;
    bShoot = bP2PlusPressed;
}

void ADataCollector::SaveData()
{
    if (CollectedTickData.Num() == 0)
    {
        return;
    }

    if (P2Flags > P1Flags)
    {
        FinalWinner = 2;
    }
    else if (P1Flags > P2Flags)
    {
        FinalWinner = 1;
    }
    else
    {
        FinalWinner = 0;
    }

    FString DataFolderPath = FPaths::Combine(FPaths::ProjectDir(), TEXT("Data"));
    IFileManager::Get().MakeDirectory(*DataFolderPath, true);

    FString FileName = FString::Printf(TEXT("GameSession_%s.csv"), *FDateTime::Now().ToString(TEXT("%Y-%m-%d-%H-%M-%S")));
    FString FullPath = FPaths::Combine(DataFolderPath, FileName);

    TArray<FString> Lines;

    for (int32 RowIdx = 0; RowIdx < CollectedTickData.Num(); ++RowIdx)
    {
        const TArray<float>& Row = CollectedTickData[RowIdx];
        const TArray<float>& Projectiles = AllProjectileInfo.IsValidIndex(RowIdx) ? AllProjectileInfo[RowIdx] : TArray<float>();

        FString Line;

        for (int32 ColIdx = 0; ColIdx < Row.Num(); ++ColIdx)
        {
            Line += FString::Printf(TEXT("%.6f"), Row[ColIdx]);
            Line += TEXT(",");
        }
        FVector2D FlagCounts = CollectedFlagCounts.IsValidIndex(RowIdx) ? CollectedFlagCounts[RowIdx] : FVector2D(-1, -1);

        if (RowIdx == CollectedTickData.Num() - 1)
        {
            if (FinalWinner == 1)
            {
                FlagCounts = FVector2D(4, 0);
            }
            else if (FinalWinner == 2)
            {
                FlagCounts = FVector2D(0, 4);
            }
        }
        Line += FString::Printf(TEXT("%.6f,%.6f,"), FlagCounts.X, FlagCounts.Y);

        int32 WinnerValue = (RowIdx == CollectedTickData.Num() - 1) ? FinalWinner : 0;
        Line += FString::Printf(TEXT("%d"), WinnerValue);

        for (float Value : Projectiles)
        {
            Line += TEXT(",");
            Line += FString::Printf(TEXT("%.6f"), Value);
        }

        Lines.Add(Line);
    }

    bool bSuccess = FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
}
