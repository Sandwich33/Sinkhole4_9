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
				if (wrapper->sendMessage(0x01)){		// connect check
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


bool UOneNetworking::cmdSystem_adbTcp(){
	system("adb forward tcp:27015 tcp:27015");
	return true;
}


// Destroys all data
void UOneNetworking::Destructor()
{
	SocketSubsystem->DestroySocket(socket);
	socket = nullptr;
	SocketSubsystem = nullptr;
}


// Send Message
bool UOneNetworking::sendMessage(const uint8 _message){
	if (!socket) return false;

	int32 BytesSent;
	// Send to
	bool success = socket->SendTo(&_message, 1, BytesSent, *remote_endpoint.ToInternetAddr());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SendMessage  %d;%d"), success, BytesSent));
	if (success && BytesSent > 0) // Success
		return true;
	else
		return false;
}
	/*
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
}*/

bool UOneNetworking::sendEnemyData(const uint8 count, const TArray<FEnemyData>& _message){
	if (!socket) return false;
	bool success;

	uint8 sendInt[8];

	// send Tag
	success = sendMessage(0x06);

	// send length
	int32 length = _message.Num();

	sendInt[0] = (length & 0xFF000000) >> 24;
	sendInt[1] = (length & 0x00FF0000) >> 16;
	sendInt[2] = (length & 0x0000FF00) >> 8;
	sendInt[3] = (length & 0x000000FF);

	int32 BytesSent;
	// Send to
	success = socket->SendTo(sendInt, 4, BytesSent, *remote_endpoint.ToInternetAddr());

	// send data
	int32 x, y;
	for (auto& data : _message){
		x = (int32)(-data.x / 12.5f);
		y = (int32)(data.y / 12.5f);

		sendInt[0] = (x & 0xFF000000) >> 24;
		sendInt[1] = (x & 0x00FF0000) >> 16;
		sendInt[2] = (x & 0x0000FF00) >> 8;
		sendInt[3] = (x & 0x000000FF);

		sendInt[4] = (y & 0xFF000000) >> 24;
		sendInt[5] = (y & 0x00FF0000) >> 16;
		sendInt[6] = (y & 0x0000FF00) >> 8;
		sendInt[7] = (y & 0x000000FF);

		success = socket->SendTo(sendInt, 8, BytesSent, *remote_endpoint.ToInternetAddr());
		if (!success)
			break;
	}


	return success;
}

bool UOneNetworking::sendPersonData(const uint8 type, const TArray<FPersonData>& _message){
	if (!socket) return false;
	bool success;

	uint8 sendInt[18];	// hp ; x;y;order;x;y; // Name

	// send Tag
	success = sendMessage(type);

	// send length
	int32 length = _message.Num();

	sendInt[0] = (length & 0xFF000000) >> 24;
	sendInt[1] = (length & 0x00FF0000) >> 16;
	sendInt[2] = (length & 0x0000FF00) >> 8;
	sendInt[3] = (length & 0x000000FF);

	int32 BytesSent;
	// Send to
	success = socket->SendTo(sendInt, 4, BytesSent, *remote_endpoint.ToInternetAddr());

	// send data
	int32 x, y;
	int32 order_x, order_y;
	FString name;
	for (auto& data : _message){
		sendInt[0] = (uint8)((int32)data.HP);	// HP
		sendInt[1] = (uint8)(data.order);		// order

		x = (int32)(-data.x / 12.5f);
		y = (int32)(data.y / 12.5f);

		sendInt[2] = (x & 0xFF000000) >> 24;
		sendInt[3] = (x & 0x00FF0000) >> 16;
		sendInt[4] = (x & 0x0000FF00) >> 8;
		sendInt[5] = (x & 0x000000FF);

		sendInt[6] = (y & 0xFF000000) >> 24;
		sendInt[7] = (y & 0x00FF0000) >> 16;
		sendInt[8] = (y & 0x0000FF00) >> 8;
		sendInt[9] = (y & 0x000000FF);

		order_x = (int32)(-data.order_x / 12.5f);
		order_y = (int32)(data.order_y / 12.5f);

		sendInt[10] = (order_x & 0xFF000000) >> 24;
		sendInt[11] = (order_x & 0x00FF0000) >> 16;
		sendInt[12] = (order_x & 0x0000FF00) >> 8;
		sendInt[13] = (order_x & 0x000000FF);

		sendInt[14] = (order_y & 0xFF000000) >> 24;
		sendInt[15] = (order_y & 0x00FF0000) >> 16;
		sendInt[16] = (order_y & 0x0000FF00) >> 8;
		sendInt[17] = (order_y & 0x000000FF);

		success = socket->SendTo(sendInt, 18, BytesSent, *remote_endpoint.ToInternetAddr());
		if (!success)
			break;
		name = data.DisplayName;

		name.AppendChar('\n');
		TCHAR *serializedChar = name.GetCharArray().GetData();
		int32 size = FCString::Strlen(serializedChar);
		int32 sent = 0;


		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SendMessage  %s (%d,%d)(%d,%d)"), serializedChar, x,y,order_x,order_y));

		success = socket->SendTo((uint8*)TCHAR_TO_UTF8(serializedChar), size, BytesSent, *remote_endpoint.ToInternetAddr());
		if (!success)
			break;
	}


	return success;
}
bool UOneNetworking::sendgetTabletNameMSG(){
	return sendMessage(0x02);
}

bool UOneNetworking::sendStartDroneCapture(){
	return sendMessage(0x04);
}
bool UOneNetworking::sendShowActivityMSG(const EAndroidActivity _message){
	if (!socket) return false;

	uint8 msg[2] = { 0x03, 0x00 };	// send Activity
	switch (_message)
	{
	case EAndroidActivity::E_WaitACT:
		msg[1] = 0x01;
		break;
	case EAndroidActivity::E_MainACT:
		msg[1] = 0x02;
		break;
	case EAndroidActivity::E_TeamACT:
		msg[1] = 0x03;
		break;
	case EAndroidActivity::E_TacticalACT:
		msg[1] = 0x04;
		break;
	case EAndroidActivity::E_DroneACT:
		msg[1] = 0x05;
		break;
	default:
		return false;
		break;
	}

	int32 BytesSent;
	// Send to
	bool success = socket->SendTo(msg, 2, BytesSent, *remote_endpoint.ToInternetAddr());
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

UTexture2D* UOneNetworking::getTexture2D(UObject * InOuter,UTextureRenderTarget2D* _RT){
	UTexture2D* Aux2DTex = _RT->ConstructTexture2D(InOuter, "Live", EObjectFlags::RF_NoFlags, CTF_Default);
	Aux2DTex->CompressionSettings = TextureCompressionSettings::TC_VectorDisplacementmap;

//#if WITH_EDITORONLY_DATA
	Aux2DTex->MipGenSettings = TextureMipGenSettings::TMGS_NoMipmaps;
//#endif
	Aux2DTex->SRGB = 0;
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

	uint8 ch[0x40002] = { 0x0, };


	int k = 0;
	//*
	for (int i = 511; i >= 0; i--){
		for (int j = 0; j < 512; j++){
			uint32 c32 = FormatedImageData[(i * 512) + j].AlignmentDummy;
			ch[k++] = ((uint8)((c32 & 0x0000FF00) >> 8));
		}
	}

	while (k < 0x40002){
		ch[k++] = 0x00;
	}

	FMemory::Free(FormatedImageData);
	int32 BytesSent;
	// Send to
	bool success = socket->SendTo(ch, 0x40438, BytesSent, *remote_endpoint.ToInternetAddr());

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("SendMessage  %d;%d"), success, BytesSent));

	if (success && BytesSent > 0) // Success
	{
		return true;
	}
	else
	{
		return false;
	}
	return true;
}