// Fill out your copyright notice in the Description page of Project Settings.

#include "ToolbarActor.h"
#include "EconomyManager.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AToolbarActor::AToolbarActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AToolbarActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> FoundEconomyManagers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AEconomyManager::StaticClass(),
		FoundEconomyManagers);
	_econ_manager = Cast<AEconomyManager>(FoundEconomyManagers[0]);

	TArray<AActor*> FoundGameTickManagers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AGameTickManager::StaticClass(),
		FoundGameTickManagers);
	GameTickManager = Cast<AGameTickManager>(FoundGameTickManagers[0]);


	testFunc();
}

// Called every frame
void AToolbarActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AToolbarActor::getEnergy()
{
	return _econ_manager->resources._energy;
}

int AToolbarActor::getMinerals()
{
	return _econ_manager->resources._minerals;;
}

int AToolbarActor::getMineralsGain()
{
	return _econ_manager->MineralBuildings;
}

int AToolbarActor::getMoney()
{
	return _econ_manager->resources._money;
}

int AToolbarActor::getMoneyGain()
{
	return _econ_manager->resources._population;
}

int AToolbarActor::getPopulation()
{
	return _econ_manager->resources._population;
}

void AToolbarActor::testFunc()
{
	UE_LOG(LogTemp, Warning, TEXT("Energy: %d, Materials: %d, Energy: %d"), getEnergy(), getMinerals(), getMoney());
	//UE_LOG(LogTemp, Warning, TEXT("Energy: "));
}