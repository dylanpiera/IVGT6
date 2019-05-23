#include "EconomyManager.h"
#include "MineralBuilding.h"
#include "EnergyBuilding.h"
#include "HouseBuilding.h"
#include "WarehouseBuilding.h"

void AEconomyManager::InitResources()
{
	resources._energy = 100 + EnergyBuildings;
	resources._minerals = 100 + MineralBuildings;
	resources._population = 8 + Houses;
	resources._money = 200 * resources._population;
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
	ActiveBuildings.Add(dynamic_cast<Building*>(new WarehouseBuilding()));
}
