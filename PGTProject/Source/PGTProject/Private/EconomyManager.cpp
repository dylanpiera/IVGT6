#include "EconomyManager.h"
#include "MineralBuilding.h"
#include "EnergyBuilding.h"
#include "HouseBuilding.h"
#include "FoodBuilding.h"

void AEconomyManager::InitResources()
{
	resources._energy = 0;
	resources._minerals = 0;
	resources._population = 0;
	resources._money = 200;
	resources._food = 0;

	resources._mine = MineralBuildings;
}

void AEconomyManager::BeginPlay()
{
	for (int i = 0; i < MineralBuildings; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating Mineral Building"));
		ActiveBuildings.Add(dynamic_cast<Building*>(new MineralBuilding()));
	}
	for (int i = 0; i < EnergyBuildings; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating Energy Building"));
		ActiveBuildings.Add(dynamic_cast<Building*>(new EnergyBuilding()));
	}
	for (int i = 0; i < Houses; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating Home"));
		ActiveBuildings.Add(dynamic_cast<Building*>(new HouseBuilding()));
	}
	for (int i = 0; i < FoodBuildings; i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Creating Food Building"));
		ActiveBuildings.Add(dynamic_cast<Building*>(new FoodBuilding()));
	}
}
