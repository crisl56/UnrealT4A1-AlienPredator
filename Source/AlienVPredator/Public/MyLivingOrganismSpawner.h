// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyLivingOrganismSpawner.generated.h"

class ALivingOrganism;

UCLASS()
class ALIENVPREDATOR_API AMyLivingOrganismSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyLivingOrganismSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float SpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<ALivingOrganism> ClassToSpawn;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void SpawnLivingOrganism();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	FTimerHandle SpawnHandle;

};
