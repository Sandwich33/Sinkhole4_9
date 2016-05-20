// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Networking.h"
#include "OneNetworking.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(OneNetworking, Log, All);

UENUM(BlueprintType)
enum class EAndroidActivity : uint8
{
	E_WaitACT		UMETA(DisplayName = "WaitACT"),
	E_MainACT		UMETA(DisplayName = "MainACT"),
	E_TeamACT		UMETA(DisplayName = "TeamACT"),
	E_TacticalACT	UMETA(DisplayName = "TacticalACT"),
	E_DroneACT		UMETA(DisplayName = "DroneACT"),
};

USTRUCT(BlueprintType)//, Blueprintable)
struct FEnemyData{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FEnemyData Struct")
		float x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FEnemyData Struct")
		float y;

	FEnemyData(){

	}
};

USTRUCT(BlueprintType)//, Blueprintable)
struct FPersonData{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPersonData Struct")
		FString DisplayName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPersonData Struct")
		float HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPersonData Struct")
		float x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPersonData Struct")
		float y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPersonData Struct")
		BOOL order;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPersonData Struct")
		float order_x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FPersonData Struct")
		float order_y;

	FPersonData(){

	}
};

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
		bool sendMessage(const uint8 _message);

	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool sendShowActivityMSG(const EAndroidActivity _message);

	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool sendgetTabletNameMSG();

	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool sendStartDroneCapture();

	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool sendEnemyData(const uint8 count,const TArray<FEnemyData>& _message);

	UFUNCTION(BlueprintCallable, Category = "OneNetworking")
		bool sendPersonData(const uint8 type,const TArray<FPersonData>& _message);

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
		static UTexture2D* getTexture2D(UObject * InOuter, UTextureRenderTarget2D* _RT);
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
