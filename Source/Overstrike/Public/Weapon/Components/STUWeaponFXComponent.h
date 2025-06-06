// Overstrike game. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUWeaponFXComponent.generated.h"

class UNiagaraSystem;
class UPhysicalMaterial;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OVERSTRIKE_API USTUWeaponFXComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USTUWeaponFXComponent();

	void PlayImpactFX(const FHitResult& Hit);

protected:
	UPROPERTY(EditDefaultsOnly, BluePrintReadWrite, Category = "VFX")
	UNiagaraSystem* DefaulEffect;

	UPROPERTY(EditDefaultsOnly, BluePrintReadWrite, Category = "VFX")
	TMap<UPhysicalMaterial*, UNiagaraSystem*> EffectsMap;
};
