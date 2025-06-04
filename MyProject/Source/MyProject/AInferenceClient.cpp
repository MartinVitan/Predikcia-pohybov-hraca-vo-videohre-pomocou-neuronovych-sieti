#include "AInferenceClient.h"

AInferenceClient::AInferenceClient()
{
	FIPv4Address IP;
	FIPv4Address::Parse(TEXT("127.0.0.1"), IP);
	TSharedRef<FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	Addr->SetIp(IP.Value);
	Addr->SetPort(5005);

	Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(NAME_Stream, TEXT("InferenceSocket"), false);
	bool bConnected = Socket->Connect(*Addr);

	if (bConnected)
	{
		UE_LOG(LogTemp, Warning, TEXT("InferenceClient: PripojenÈ na Python server"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("InferenceClient: Nepodarilo sa pripojiù na Python server"));
	}
}

TArray<float> AInferenceClient::SendInputAndReceiveOutput(const TArray<float>& InputData)
{
	TArray<float> Outputs;
	if (!Socket || !Socket->GetConnectionState() == SCS_Connected)
	{
		UE_LOG(LogTemp, Error, TEXT("Socket nie je pripojen˝!"));
		return Outputs;
	}

	TArray<uint8> SendBuffer;
	SendBuffer.SetNumUninitialized(sizeof(float) * InputData.Num());
	FMemory::Memcpy(SendBuffer.GetData(), InputData.GetData(), SendBuffer.Num());

	int32 BytesSent = 0;
	Socket->Send(SendBuffer.GetData(), SendBuffer.Num(), BytesSent);

	uint8 RecvBuffer[sizeof(float) * 7];
	int32 BytesRead = 0;
	if (Socket->Recv(RecvBuffer, sizeof(float) * 7, BytesRead))
	{
		float* Result = reinterpret_cast<float*>(RecvBuffer);
		for (int i = 0; i < 7; ++i)
		{
			Outputs.Add(Result[i]);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Nepodarilo sa prijaù odpoveÔ zo servera"));
	}

	return Outputs;
}

AInferenceClient::~AInferenceClient()
{
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
	}
}
