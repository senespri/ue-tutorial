﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SAction.h"
#include "Components/ActorComponent.h"
#include "SActionComponent.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UE5TUTORIAL_API USActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Tags")
	FGameplayTagContainer ActiveGameplayTags;

	UFUNCTION(BlueprintCallable, Category="Actions")
	void AddAction(TSubclassOf<USAction> ActionClass);

	UFUNCTION(BlueprintCallable, Category="Action")
	bool StartActionByName(AActor* Instigator, FName ActionName);

	UFUNCTION(BlueprintCallable, Category="Action")
	bool StopActionByName(AActor* Instigator, FName ActionName);

	USActionComponent();

protected:
	/* Granted abilities at game start */
	UPROPERTY(EditAnywhere, Category="Actions")
	TArray<TSubclassOf<USAction>> DefaultActions;

	UPROPERTY()
	TArray<TObjectPtr<USAction>> Actions;

	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;
};
