// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SAction_ProjectileAttack.generated.h"

/**
 *
 */
UCLASS()
class UE5TUTORIAL_API USAction_ProjectileAttack : public USAction
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(VisibleAnywhere, Category="Effects")
	FName HandSocketName;

	UPROPERTY(EditAnywhere, Category="Attack");
	float AttackAnimDelay = 0.2f;

	UPROPERTY(EditAnywhere, Category="Attack");
	UAnimMontage* AttackAnim;

	UPROPERTY(EditAnywhere, Category="Attack");
	UParticleSystem* CastingEffect;

	UFUNCTION()
	void AttackDelay_Elapsed(ACharacter* InstigatorCharacter);

public:
	virtual void StartAction_Implementation(AActor* Instigator) override;

	USAction_ProjectileAttack();
};
