// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Networking.h"
#include "OneNetworking.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(OneNetworking, Log, All);

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class SINKHOLE_API UOneNetworking : public UObject
{
	GENERATED_BODY()

public:
	// Create
	static UOneNetworking* createNetworking();

	UFUNCTION(BlueprintPure, Category = "OneNetworking")
		static UOneNetworking* createTCPClient(const FString& _socket_description, const FString& _ip_address, const int32 _port);

	UFUNCTION(BlueprintPure, Category = "OneNetworking_temp")
		static bool cmdSystem_adbTcp();

	// Destroys all data
	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		void Destructor();

	// Send Message
	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool sendMessage(const FString _message);

	// Grab Data
	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		void anyMessages(bool& _is_in_msg, FString& _message);

	FString GrabWaitingMessage();
	static FString StringFromBinaryArray(const TArray<uint8>&  BinaryArray);


	// else
	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		FString getLocalIpAddress();

	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool isConnection();

	//--------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "OneNetworking_temp")
		UTexture2D* getTexture2D(UTextureRenderTarget2D* _message);////////////////////////////////////////////
	//UTextureRenderTarget2D* aa;
	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool sendImage(UTexture2D* t2d);////////////////////////////////////////////
	//--------------------------------------------------------------------------------------------------------------------

private:
	FSocket* socket;
	ISocketSubsystem* SocketSubsystem;
	FString socket_description;
	FIPv4Endpoint remote_endpoint;
	FIPv4Address remote_adress;
	TArray<uint8> received_data;

	bool is_connect;
};
