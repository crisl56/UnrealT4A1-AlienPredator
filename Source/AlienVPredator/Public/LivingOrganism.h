// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LivingOrganism.generated.h"

UCLASS()
class ALIENVPREDATOR_API ALivingOrganism : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALivingOrganism();

	// This is my awesome Tooltip
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (ClampMin = 0, ClampMax = 100), Category = "Rohit's Awesome Category")
	int32 MyFirstVariable;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, DisplayName = "Designers Awesome Color", meta = (Tooltip = "this is my tooltip"))
	FColor MyColor;


	void MyFirstFunction(int32 param);

	UFUNCTION(BlueprintCallable)
	void BlueprintCallableFunction(FString designerName);

	UFUNCTION(BlueprintCallable)
	int32 MySecondBlueprintCallableFunction(FString designerName,const float& myParam);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "VFX")
	void MyThirdFunction(int32 param);

	UFUNCTION(BlueprintImplementableEvent)
	void MyImplementableEvent();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float AddTwoNumbers(float param1, float param2);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
