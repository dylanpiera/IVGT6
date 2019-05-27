// Fill out your copyright notice in the Description page of Project Settings.

#include "GameTickManager.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AGameTickManager::AGameTickManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	currentHour = 0;
	currentDay = 0;
	dayOfWeek = 0;
	currentMonth = 0;
	currentYear = 2100;

	timer = 4.0f;
	timeMultiplier = 1;

	days = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

	months = { "January", "February", "March", "April", "May", "June",
				"July", "August", "September", "October", "November", "December" };

	dayName = days[currentDay];
	monthName = months[currentMonth];

	bCanTick = true;
}

// Called when the game starts or when spawned
void AGameTickManager::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AEconomyManager::StaticClass(),
		FoundActors);
	EconomyManager = Cast<AEconomyManager>(FoundActors[0]);

	EconomyManager->InitResources();
}
	
// Called every frame
void AGameTickManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GameTick();

	if (Debug) {
		UE_LOG(LogTemp, Warning, TEXT("%d"), currentHour);
		UE_LOG(LogTemp, Warning, TEXT("%d"), dayOfWeek);
		UE_LOG(LogTemp, Warning, TEXT("%d"), currentDay);
		UE_LOG(LogTemp, Warning, TEXT("%d"), currentMonth);
		UE_LOG(LogTemp, Warning, TEXT("%d"), currentYear);
	}
}

void AGameTickManager::GameTick()
{
	GameTickHour();
	
	UE_LOG(LogTemp, Warning, TEXT("Energy: %d"), EconomyManager->resources._energy);
	UE_LOG(LogTemp, Warning, TEXT("Minerals: %d"), EconomyManager->resources._minerals);
	UE_LOG(LogTemp, Warning, TEXT("Money: %d"), EconomyManager->resources._money);
	UE_LOG(LogTemp, Warning, TEXT("Population: %d"), EconomyManager->resources._population);
}

//managed the hourly tick
void AGameTickManager::GameTickHour()
{
	UINT32 hourNow = currentHour;
	if (bCanTick)
	{
		bCanTick = false;
		hourNow++;

		//refactor for optimal use. Need buttons for this.
		//GetWorldTimerManager().SetTimer(GameTickTimerHandle, this, &AGameTickManager::ResetTimer, timer / timeMultiplier, false);
		GetWorldTimerManager().SetTimer(GameTickTimerHandle, this, &AGameTickManager::ResetTimer, 0.005f, false);
		currentHour = hourNow;

		if(currentHour > 23)
		{
			GameTickDay();
			currentHour = 0;
		}
	}
}


//This is where the magic should happen!
//Manages the dayly tick
void AGameTickManager::GameTickDay()
{
	// Update Resources
	EconomyManager->resources._population = 0;
	EconomyManager->resources._energy = 0;
	for (UBuilding* building : EconomyManager->ActiveBuildings)
	{
		building->BuildingFunction(EconomyManager->resources);
	}
	EconomyManager->resources._money += 10 * EconomyManager->resources._population;

	dayOfWeek++;
	currentDay++;

	//keeps track on what day of the week it is
	if(dayOfWeek > 6)
	{
		dayOfWeek = 0;
	}
	dayName = days[dayOfWeek];

	//keeps track of the day in the month and ticks when month is done.
	if(currentDay > 29)
	{
		GameTickMonth();
		currentDay = 0;
	}

}

void AGameTickManager::GameTickMonth()
{
	currentMonth++;

	//keeps track if a year in months has passed.
	if(currentMonth > 11)
	{
		GameTickYear();
		currentMonth = 0;
	}
	monthName = months[currentMonth];
}

//add years
void AGameTickManager::GameTickYear()
{
	currentYear++;
}

void AGameTickManager::ResetTimer()
{
	bCanTick = true;
	GetWorldTimerManager().ClearTimer(GameTickTimerHandle);
}

//set multiplier to 1
void AGameTickManager::SetSpeedTimeOne() { timeMultiplier = 1; }

//set multiplier to 2
void AGameTickManager::SetSpeedTimeTwo() { timeMultiplier = 2; }

//set multiplier to 4
void AGameTickManager::SetSpeedTimeFour() { timeMultiplier = 4; }






