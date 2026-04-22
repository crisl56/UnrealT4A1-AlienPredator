// Copyright Rohit VFS 2023-2024

#pragma once

#include "CoreMinimal.h"
#include "LivingOrganism.h"
#include "DamageInterface.h"
#include "Predator.generated.h"

/**
 * 
 */
UCLASS()
class ALIENVPREDATOR_API APredator : public ALivingOrganism , public IDamageInterface
{
	GENERATED_BODY()

public:

	void TakeLivingDamage_Implementation() override;
	
};
