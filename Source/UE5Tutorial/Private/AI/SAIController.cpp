// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"


// Called when the game starts or when spawned
void ASAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);
	if (BehaviorTree == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing behaviour tree"));
	}

	if (APawn* MyPawn = UGameplayStatics::GetPlayerPawn(this, 0))
	{
		if (UBlackboardComponent* blackboard = GetBlackboardComponent())
		{
			blackboard->SetValueAsVector("MoveToLocation", MyPawn->GetActorLocation());

			blackboard->SetValueAsObject("TargetActor", MyPawn);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Missing blackboard"));
		}
	}
}