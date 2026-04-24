// Copyright Rohit VFS 2023-2024


#include "PredatorProjectile.h"

#include "DamageInterface.h"
#include "GameFramework/ProjectileMovementComponent.h"

APredatorProjectile::APredatorProjectile()
{
	DamageRadius = 150.0f;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(MeshComponent);
	MeshComponent->SetSimulatePhysics(false);
	MeshComponent->SetNotifyRigidBodyCollision(true);
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 3500.0f;
	ProjectileMovement->MaxSpeed = 3500.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	
	InitialLifeSpan = 5.0f;
}

void APredatorProjectile::BeginPlay()
{
	Super::BeginPlay();
	OnActorHit.AddUniqueDynamic(this, &APredatorProjectile::OnProjectileHit);
}

void APredatorProjectile::OnProjectileHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse,
	const FHitResult& Hit)
{
	if (!OtherActor || OtherActor == Owner) return;
	
	if (OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_TakeLivingDamage(OtherActor);
	}
	
	Destroy();
}
