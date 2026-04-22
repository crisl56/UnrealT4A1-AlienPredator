// Copyright Rohit VFS 2023-2024


#include "MyLivingOrganismSpawner.h"
#include "LivingOrganism.h"

// Sets default values
AMyLivingOrganismSpawner::AMyLivingOrganismSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpawnDelay = 3.0f;
}

// Called when the game starts or when spawned
void AMyLivingOrganismSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnHandle, this, &AMyLivingOrganismSpawner::SpawnLivingOrganism, SpawnDelay, true);
	
}

void AMyLivingOrganismSpawner::SpawnLivingOrganism()
{
	FActorSpawnParameters MySpawnParams;
	MySpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	GetWorld()->SpawnActor<ALivingOrganism>(ClassToSpawn, GetActorLocation(), GetActorForwardVector().Rotation(), MySpawnParams);
}

// Called every frame
void AMyLivingOrganismSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

