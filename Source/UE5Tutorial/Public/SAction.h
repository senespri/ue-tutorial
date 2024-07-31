﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SAction.generated.h"

/**
 *
 */
UCLASS(Blueprintable)
class UE5TUTORIAL_API USAction : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Action")
	void StartAction(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category="Action")
	void StopAction(AActor* Instigator);

	UPROPERTY(EditDefaultsOnly, Category="Action")
	FName ActionName;

	UWorld* GetWorld() const override;
};
