// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "LivingOrganism.h"
#include "DamageInterface.h"
#include "Predator.generated.h"

/**
 * 
 */

class APredatorProjectile;
class AAlien;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPredatorCharged, APredator*, Predator);

UCLASS()
class ALIENVPREDATOR_API APredator : public ALivingOrganism , public IDamageInterface
{
	GENERATED_BODY()

public:
	APredator();

	virtual void TakeLivingDamage_Implementation() override;
	
	UPROPERTY(BlueprintAssignable, Category = "Predator | Events")
	FOnPredatorCharged OnPredatorCharged;
	
protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Predator | Combat")
	float ChargeTime;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Predator | Combat")
	float shootRadius;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Predator | Combat")
	TSubclassOf<APredatorProjectile> ProjectileClass;
	
private:
	FTimerHandle ChargeTimerHandle;
	
	UFUNCTION()
	void OnChargeComplete();
	
	AAlien* FindNearestAlien() const;
	
	void FireAtAlien(AAlien* TargetAlien);
	
};
