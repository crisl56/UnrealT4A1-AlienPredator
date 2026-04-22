// Copyright Rohit VFS 2023-2024


#include "Alien.h"
#include "Components/StaticMeshComponent.h"
#include "DamageInterface.h"
#include "Components/ArrowComponent.h"

AAlien::AAlien()
{
	// Create an instance of Static mesh and Arrow Component and add it to the Alien actor

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("NOSE"));

	SetRootComponent(BodyMesh);

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	// Enabling Physics
	BodyMesh->SetSimulatePhysics(true);
	BodyMesh->SetConstraintMode(EDOFMode::XYPlane);
	BodyMesh->SetNotifyRigidBodyCollision(true);
}

void AAlien::Tick(float deltaSeconds)
{
	Super::Tick(deltaSeconds);

	AddForceToBody();
}

void AAlien::BeginPlay()
{
	Super::BeginPlay();

	OnActorHit.AddUniqueDynamic(this, &AAlien::OnAlienHit);
}

void AAlien::OnAlienHit_Implementation(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	MyGooEvent.Broadcast(true, 15.0f);
	if (OtherActor->Implements<UDamageInterface>())
	{
		IDamageInterface::Execute_TakeLivingDamage(OtherActor);
	}
}

void AAlien::AddForceToBody()
{
	const FVector forceToAdd = BodyMesh->GetMass() * (GetActorForwardVector() * MovementSpeed);
	BodyMesh->AddForce(forceToAdd, NAME_None, true);
}
