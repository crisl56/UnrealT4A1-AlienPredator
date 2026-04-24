// Copyright Rohit VFS 2023-2024


#include "Predator.h"

#include "Alien.h"
#include "PredatorProjectile.h"
#include "Kismet/GameplayStatics.h"

APredator::APredator()
{
	ChargeTime = 3.0f;
	shootRadius = 2000.0f;
}

void APredator::TakeLivingDamage_Implementation()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Red, TEXT("Predator: Took Damage!"));
}

void APredator::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(
		ChargeTimerHandle,
		this,
		&APredator::OnChargeComplete,
		ChargeTime,
		true
		);
	
	
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 5.0f, FColor::Cyan, TEXT("Predator: Charging..."));
}

void APredator::OnChargeComplete()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Yellow, TEXT("Predator: Charged!"));
	
	OnPredatorCharged.Broadcast(this);
	
	AAlien* TargetAlien = FindNearestAlien();
	if (TargetAlien)
	{
		FireAtAlien(TargetAlien);
	}
	else if (GEngine)
	{
        GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Orange, TEXT("Predator: No aliens in range."));	
	}
}

AAlien* APredator::FindNearestAlien() const
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAlien::StaticClass(), FoundActors);
	
	AAlien* FoundAlien = nullptr;
	float NearestDistSq = FMath::Square(shootRadius);
	
	for (AActor* Actor : FoundActors)
	{
		AAlien* Alien = Cast<AAlien>(Actor);
		if (!Alien) continue;
		
		const float DistSq = FVector::DistSquared(GetActorLocation(), Alien->GetActorLocation());
		if (DistSq < NearestDistSq)
		{
			NearestDistSq = DistSq;
			FoundAlien = Alien;
		}
	}
	
	return FoundAlien;
	
}

void APredator::FireAtAlien(AAlien* TargetAlien)
{
	if (!ProjectileClass) return;
	
	const FVector Direction = (TargetAlien->GetActorLocation() - GetActorLocation()).GetSafeNormal();
	const FVector SpawnLocation = GetActorLocation() + Direction * 150.0f;
	const FRotator SpawnRotation = Direction.Rotation();
	
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	
	if (UWorld* World = GetWorld())
	{
		APredatorProjectile* Projectile = World->SpawnActor<APredatorProjectile>(
			ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
		
		if (Projectile && GEngine)
			GEngine->AddOnScreenDebugMessage(INDEX_NONE, 3.0f, FColor::Orange, TEXT("Predator: Fired!"));	
	}
}
