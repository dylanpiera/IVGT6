// Fill out your copyright notice in the Description page of Project Settings.

#include "ConstructionTimerActor.h"

// Sets default values
AConstructionTimerActor::AConstructionTimerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AConstructionTimerActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AConstructionTimerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AConstructionTimerActor::StartConstruction(Building* building, int TimeInHours)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Construction starts!"));

	UWorld* World = GetWorld();
	if (World)
	{
		FTimerHandle ConstructionHandle;
		// If the timer has expired or does not exist, start it  
		if ((ConstructionHandle.IsValid() == false))
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Valid handle : SetTimer()"));
			FTimerDelegate TimerDel = FTimerDelegate::CreateUObject(this, &AConstructionTimerActor::FinishConstruction, building);
			//TimerDel.BindUFunction(this, &AConstructionTimerActor::FinishConstruction, building);
			GetWorldTimerManager().SetTimer(ConstructionHandle, TimerDel, 1.f, false);
			//GetWorldTimerManager().SetTimer(ConstructionHandle, this, &AConstructionTimerActor::FinishConstruction, 1.0f, false);
		}
		else
		{
			if (World->GetTimerManager().IsTimerPaused(ConstructionHandle) == true)
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Unpause Timer"));
				World->GetTimerManager().UnPauseTimer(ConstructionHandle);
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Pause Timer"));
				World->GetTimerManager().PauseTimer(ConstructionHandle);
			}
		}
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("Construction Timer not in scene. 'UWorld' is NULL."));
	}
}

void AConstructionTimerActor::FinishConstruction(Building* building)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Time's Up! Finishing construction!"));
	building->WhenConstructionFinishes();
}

void AConstructionTimerActor::test()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("TESTING Construction..."));
}
