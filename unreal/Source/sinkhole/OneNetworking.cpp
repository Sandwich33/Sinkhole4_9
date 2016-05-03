// Fill out your copyright notice in the Description page of Project Settings.

#include "sinkhole.h"
#include "OneNetworking.h"
#include <string>
#include <stdlib.h>


DEFINE_LOG_CATEGORY(OneNetworking);

// Create
UOneNetworking* UOneNetworking::createNetworking()
{
	return (UOneNetworking*)StaticConstructObject(UOneNetworking::StaticClass());
}


UOneNetworking* UOneNetworking::createTCPClient(const FString& _socket_description, const FString& _ip_address, const int32 _port){

	system("adb forward tcp:27015 tcp:27015");

	UOneNetworking* wrapper = createNetworking();

	wrapper->SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
	wrapper->socket_description = *_socket_description;

	FIPv4Address::Parse(*_ip_address, wrapper->remote_adress);
	wrapper->remote_endpoint = FIPv4Endpoint(wrapper->remote_adress, _port);

	// First set our socket null
	wrapper->socket = nullptr;
	wrapper->is_connect = false;

	if (wrapper->SocketSubsystem != nullptr) // If socket subsytem is good
	{

		wrapper->socket = FTcpSocketBuilder(wrapper->socket_description).Build();

		if (wrapper->socket != nullptr) // Is our socket created
		{
			// Setup the socket 
			bool Error = !wrapper->socket->Connect(*wrapper->remote_endpoint.ToInternetAddr());

			if (Error)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, wrapper->socket_description);
				wrapper->SocketSubsystem->DestroySocket(wrapper->socket);
				wrapper->socket = nullptr;

			}
			else{
				if (wrapper->sendMessage(FString::Printf(TEXT("checkConnect")))){
					wrapper->is_connect = true;
					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, wrapper->socket_description);
				}
				else{

					//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, wrapper->socket_description);
					wrapper->SocketSubsystem->DestroySocket(wrapper->socket);
					wrapper->socket = nullptr;
				}
			}
		}
	}

	return wrapper;
}


// Destroys all data
void UOneNetworking::Destructor()
{
	SocketSubsystem->DestroySocket(socket);
	socket = nullptr;
	SocketSubsystem = nullptr;
}


// Send Message
bool UOneNetworking::sendMessage(FString _message){
	if (!socket) return false;

	int32 BytesSent;
	//FTimespan waitTime = FTimespan(10);

	_message.AppendChar('\n');
	TCHAR *serializedChar = _message.GetCharArray().GetData();
	int32 size = FCString::Strlen(serializedChar);
	int32 sent = 0;

	// Send to
	bool success = socket->SendTo((uint8*)TCHAR_TO_UTF8(serializedChar), size, BytesSent, *remote_endpoint.ToInternetAddr());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SendMessage  %d;%d"), success, BytesSent));
	if (success && BytesSent > 0) // Success
		return true;
	else
		return false;
}

void UOneNetworking::anyMessages(bool& _is_in_msg, FString& _message)
{
	uint32 Size;
	bool has = false;

	if (socket->HasPendingData(Size))
	{
		has = true;
		_message = GrabWaitingMessage();
	}

	_is_in_msg = has;
	return;
}

FString UOneNetworking::GrabWaitingMessage()
{
	uint32 Size;

	TSharedRef<FInternetAddr> Sender = SocketSubsystem->CreateInternetAddr();
	while (socket->HasPendingData(Size))
	{
		int32 Read = 0;
		received_data.Init(FMath::Min(Size, 65507u));
		socket->RecvFrom(received_data.GetData(), received_data.Num(), Read, *Sender);
	}
	return StringFromBinaryArray(received_data);
}

FString UOneNetworking::StringFromBinaryArray(const TArray<uint8>& _binary_array)
{
	//Create a string from a byte array!
	const std::string cstr(reinterpret_cast<const char*>(_binary_array.GetData()), _binary_array.Num() - 1);
	return FString(cstr.c_str()).Trim();
}

FString UOneNetworking::getLocalIpAddress()
{
	bool canBind = false;
	TSharedRef<FInternetAddr> localIp = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, canBind);

	if (localIp->IsValid())
	{
		return localIp->ToString(false);
	}

	return TEXT("");
}

bool UOneNetworking::isConnection()
{
	return is_connect;
}

//===========================================================================================================================
UTexture2D* UOneNetworking::getTexture2D(UTextureRenderTarget2D* _RT){
	UTexture2D* Aux2DTex = _RT->ConstructTexture2D(this, "AlphaTex", EObjectFlags::RF_NoFlags, CTF_Default);
	Aux2DTex->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;

#if WITH_EDITORONLY_DATA
	Aux2DTex->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
#endif
	Aux2DTex->SRGB = 1;
	//Update the texture with new variable values.
	Aux2DTex->UpdateResource();

	return Aux2DTex;
}

//*
bool UOneNetworking::sendImage(UTexture2D* t2d){
	if (!socket) return false;


	t2d->UpdateResource();

	FColor* FormatedImageData = NULL;
	t2d->PlatformData->Mips[0].BulkData.GetCopy((void**)&FormatedImageData);

	FILE *fp = fopen("C:\\Users\\0xFF00FF00\\Documents\\Scan\\temp.bmp", "wb");
	for (int i = 0; i < 512 * 512; i++){
		uint32 c32 = FormatedImageData[i].AlignmentDummy;
		fprintf(fp, "%c", ((uint8)((c32 & 0xFF000000) >> 24)));
		fprintf(fp, "%c", ((uint8)((c32 & 0x00FF0000) >> 16)));
		fprintf(fp, "%c", ((uint8)((c32 & 0x0000FF00) >> 8)));
		fprintf(fp, "%c", ((uint8)((c32 & 0x000000FF) >> 0)));

	}
	fclose(fp);

	/*
	for (int i = 0; i < 512; i++){
	uint8 color[514];
	color[0] = (uint8)(i & 0x000000FF);//.Add();
	color[1] = (uint8)((i & 0x0000FF00) >> 8);
	for (int j = 0; j < 10; j++){
	uint32 c32 = FormatedImageData[(i * 512) + j].AlignmentDummy;
	color[j + 2] = ((uint8)((c32 & 0x00ff0000) >> 16));	//G
	UE_LOG(YourLog, Log, TEXT("%d] ;; 0x%02X ;; %08x"), j, color[j + 2], c32);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, );
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("i ;; %d ; %s"), i, color));
	//FPlatformProcess::Sleep(5);
	}*/
	FMemory::Free(FormatedImageData);
	/*
	const bool bAutoDeleteSelf = false;
	const bool bAutoDeleteRunnable = false;

	RunSend *sendRun = new RunSend(this,t2d);
	FRunnableThread *thread = FRunnableThread::Create(sendRun, TEXT("FPrimeNumberWorker"), bAutoDeleteSelf, bAutoDeleteRunnable, 0, TPri_BelowNormal);
	*/
	/*

	//FColor* FormatedImageData = NULL;
	t2d->PlatformData->Mips[0].BulkData.GetCopy((void**)&FormatedImageData);


	int32 BytesSent;
	for (int i = 0; i<5; i++){
	TArray<uint8> color;
	color.Add((uint8)(i & 0x000000FF));
	color.Add((uint8) ((i & 0x0000FF00)>>8));
	for (int j = 0; j < 512;j++){
	uint32 c32 = FormatedImageData[(i*512)+j].AlignmentDummy;
	color.Add((uint8)((c32 & 0x00ff0000) >> 16));	//G
	}
	bool success = socket->SendTo((uint8*)&color, 514, BytesSent, *remote_endpoint.ToInternetAddr());
	if (success && BytesSent > 0) // Success
	{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("true")));
	//		return true;
	}
	else
	{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("false")));
	//	return false;
	}
	FPlatformProcess::Sleep(1);
	}
	*/
	//int32 sent = 0;
	//bool success = socket->SendTo((uint8*)FormatedImageData, 512*4, BytesSent, *remote_endpoint.ToInternetAddr());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("aaa  %x"),color[0]));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("aaa  %x"), FormatedImageData[0].AlignmentDummy));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("aaa  %x"), FormatedImageData[1].AlignmentDummy));
	//FMemory::Free(FormatedImageData);
	return true;
}