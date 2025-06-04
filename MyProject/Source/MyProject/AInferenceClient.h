#pragma once

#include "CoreMinimal.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Networking.h"

class MYPROJECT_API AInferenceClient
{
public:
	AInferenceClient();
	~AInferenceClient();
	TArray<float> SendInputAndReceiveOutput(const TArray<float>& InputData);

private:
	FSocket* Socket;
};
