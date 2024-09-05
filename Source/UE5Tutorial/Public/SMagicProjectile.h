#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SProjectileBase.h"
#include "GameFramework/Actor.h"
#include "SMagicProjectile.generated.h"

class USActionEffect;
class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS()
class UE5TUTORIAL_API ASMagicProjectile : public ASProjectileBase
{
	GENERATED_BODY()

public:
	ASMagicProjectile();

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	float Damage = 20;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	FGameplayTag ParryTag;

	UPROPERTY(EditDefaultsOnly, Category = "Damage")
	TSubclassOf<USActionEffect> BurningActionClass;

	UFUNCTION()
	void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
