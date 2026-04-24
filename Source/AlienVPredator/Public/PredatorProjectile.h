// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PredatorProjectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class ALIENVPREDATOR_API APredatorProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	APredatorProjectile();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> MeshComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UProjectileMovementComponent> ProjectileMovement;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	float DamageRadius;
	
private:
	UFUNCTION()
	void OnProjectileHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
	
};
