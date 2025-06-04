// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" 
#include "GameFramework/Actor.h"
#include "DataCollector.generated.h"

UCLASS()
class MYPROJECT_API ADataCollector : public AActor
{
	GENERATED_BODY()
	
public:	
	ADataCollector();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	USceneComponent* Root;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FString InferenceModelType = "Supervised";

	UPROPERTY()
	ACharacter* Player1;
	UPROPERTY()
	ACharacter* Player2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI Mode")
	bool bUseAIForP2 = false;

	TArray<float> SendInputToModel(const TArray<float>& InputData);

	FSocket* ModelSocket;
	bool bSocketConnected;

	UFUNCTION(BlueprintCallable, Category = "AI")
	void GetAIInput(bool& bUp, bool& bDown, bool& bLeft, bool& bRight, bool& bDiagLeft, bool& bDiagRight, bool& bShoot);

	TMap<FString, float> LastInputTimes;
	TMap<FString, float> LastPressStartTimes;
	TMap<FString, float> LastCooldownEndTimes;

	TArray<float> LastModelOutputs;

	int32 UsedPort;

	FVector Player1Position;
	FRotator Player1Rotation;

	FVector Player2Position;
	FRotator Player2Rotation;

	bool bP1WPressed;
	bool bP1APressed;
	bool bP1SPressed;
	bool bP1DPressed;
	bool bP1QPressed;
	bool bP1EPressed;
	bool bP1SpacePressed;

	bool bP2Num4Pressed;
	bool bP2Num5Pressed;
	bool bP2Num8Pressed;
	bool bP2Num6Pressed;
	bool bP2Num7Pressed;
	bool bP2Num9Pressed;
	bool bP2PlusPressed;

	UPROPERTY()
	TArray<AActor*> Flags;
	UPROPERTY()
	TArray<int32> FlagStates;
	UPROPERTY()
	TArray<int32> LastKnownOwners;
	bool bFirstTick = true;

	bool bP2SeesP1 = false;
	FVector LastKnownP1Position;
	FRotator LastKnownP1Rotation;

	TMap<AActor*, int32> ProjectileOwnerMap;
	TSet<AActor*> CurrentlyVisibleProjectiles;

	UPROPERTY()
	TArray<int32> LastKnownFlagStates;

	UPROPERTY()
	TArray<AActor*> ActiveProjectiles;

	TMap<AActor*, FVector> LastKnownProjectilePositions;
	TMap<AActor*, float> ProjectileTTL;

	bool bP2InputEnabled = false;

	float SpaceBarCooldown = 0.0f;
	float NumpadPlusCooldown = 0.0f;
	const float InputCooldownTime = 1.0f;

	bool bP1SpacePrevState = false;
	bool bP2PlusPrevState = false;

	float GameTimer;
	bool bIsGameActive;

	bool bGameEnded = false;

	bool bDataSavingStarted = false;

	bool pWon = false;

	TArray<TArray<float>> AllProjectileInfo;

	int32 P1Flags = 0;
	int32 P2Flags = 0;

	TArray<int32> ActualFlagStates;
	TArray<FVector2D> CollectedFlagCounts;

	bool bWallsDetected[8] = { false, false, false, false, false, false, false, false };

	TArray<TArray<float>> CollectedTickData;

	int32 FinalWinner = -1;

	void SaveData();
};  
