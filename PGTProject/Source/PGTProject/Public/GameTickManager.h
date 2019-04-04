// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameTickManager.generated.h"

UCLASS()
class PGTPROJECT_API AGameTickManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameTickManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	UINT32 currentHour;
	UINT32 currentDay;
	UINT32 dayOfWeek;
	UINT32 currentMonth;
	UINT32 currentYear;

	UINT32 timeMultiplier;
	float timer;

	TArray<FString> days;
	TArray<FString> months;
	FString dayName;
	FString monthName;

	FTimerHandle GameTickTimerHandle;
	bool bCanTick;

	UFUNCTION()
	void GameTick();
	void GameTickHour();
	void GameTickDay();
	void GameTickMonth();
	void GameTickYear();

	void ResetTimer();

	void SetSpeedTimeOne();
	void SetSpeedTimeTwo();
	void SetSpeedTimeFour();
};
