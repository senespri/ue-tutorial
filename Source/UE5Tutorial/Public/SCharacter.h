// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SActionComponent.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class USAttributeComponent;
class USInteractionComponent;
class UCameraComponent;
class USpringArmComponent;
class UAnimMontage;

UCLASS()
class UE5TUTORIAL_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USAttributeComponent* AttributeComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USActionComponent* ActionComp;

	UPROPERTY(VisibleAnywhere, Category="Effects")
	FName TimeToHitParamName;

	void MoveForward(float Value);
	void MoveRight(float Value);

	void SprintStart();
	void SprintStop();

	void PrimaryAttack();

	void BlackHoleAttack();

	void Dash();

	void PrimaryInteract();

	UFUNCTION()
	void OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float Delta);

	virtual void PostInitializeComponents() override;

	virtual FVector GetPawnViewLocation() const override;
public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(Exec)
	void HealSelf(float Amount = 100);
};
