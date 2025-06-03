#include "InferenceClientHelper.h"

InferenceClientHelper::InferenceClientHelper()
{
	Socket = nullptr;
}

bool InferenceClientHelper::Connect()
{
	FIPv4Address IP;
	FIPv4Address::Parse(TEXT("127.0.0.1"), IP);

	TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	Addr->SetIp(IP.Value);
	Addr->SetPort(5005);

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("InferenceSocket"), false);

	return Socket->Connect(*Addr);
}

TArray<float> InferenceClientHelper::SendInputAndReceiveOutput(const TArray<float>& Input)
{
	TArray<float> Output;

	if (!Socket || Socket->GetConnectionState() != SCS_Connected)
		return Output;

	TArray<uint8> SendBuffer;
	SendBuffer.SetNumUninitialized(sizeof(float) * Input.Num());
	FMemory::Memcpy(SendBuffer.GetData(), Input.GetData(), SendBuffer.Num());

	int32 BytesSent = 0;
	Socket->Send(SendBuffer.GetData(), SendBuffer.Num(), BytesSent);

	uint8 RecvBuffer[sizeof(float) * 7];
	int32 BytesRead = 0;
	if (Socket->Recv(RecvBuffer, sizeof(float) * 7, BytesRead))
	{
		float* Result = reinterpret_cast<float*>(RecvBuffer);
		for (int i = 0; i < 7; ++i)
		{
			Output.Add(Result[i]);
		}
	}
	return Output;
}

InferenceClientHelper::~InferenceClientHelper()
{
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}
}
