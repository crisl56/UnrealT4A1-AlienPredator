// Copyright Rohit VFS 2023-2024


#include "LivingOrganism.h"
#include "Engine/Engine.h"

// Sets default values
ALivingOrganism::ALivingOrganism()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyFirstVariable = 100;
	MyColor = FColor::Magenta;
}

void ALivingOrganism::MyFirstFunction(int32 param)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, MyColor, FString::Printf(TEXT("Value :  %d"), param));
}

void ALivingOrganism::BlueprintCallableFunction(FString designerName)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, MyColor, *designerName);
}

int32 ALivingOrganism::MySecondBlueprintCallableFunction(FString designerName,const float& myParam)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, MyColor, *designerName);
	MyThirdFunction(25);
	return 25;
}

void ALivingOrganism::MyThirdFunction_Implementation(int32 param)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, MyColor, TEXT("This is My CPP FUNCTION"));
	MyImplementableEvent();
}

float ALivingOrganism::AddTwoNumbers(float param1, float param2)
{
	return param1 + param2;
}

// Called when the game starts or when spawned
void ALivingOrganism::BeginPlay()
{
	Super::BeginPlay();
	MyFirstFunction(MyFirstVariable);
	// GEngine->AddOnScreenDebugMessage(INDEX_NONE, 10.0f, MyColor, FString::Printf(TEXT("MyFirstVariable %d"), MyFirstVariable));
}

// Called every frame
void ALivingOrganism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

