#pragma once

#include "CoreMinimal.h"
#include "Sockets.h"
#include "SocketSubsystem.h"
#include "Networking.h"

class MYPROJECT_API InferenceClientHelper
{
public:
	InferenceClientHelper();
	~InferenceClientHelper();

	bool Connect();
	TArray<float> SendInputAndReceiveOutput(const TArray<float>& Input);

private:
	FSocket* Socket;
};
