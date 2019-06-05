#include "EconomyManager.h"
#include "MineralBuilding.h"
#include "EnergyBuilding.h"
#include "HouseBuilding.h"
#include "FoodBuilding.h"
#include <ActiveState.h>

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
		auto building = Cast<UBuilding>(NewObject<UMineralBuilding>(UMineralBuilding::StaticClass(), FName("MineralBuilding")));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
	}
	for (int i = 0; i < EnergyBuildings; i++)
	{
		auto building = Cast<UBuilding>(NewObject<UEnergyBuilding>(UEnergyBuilding::StaticClass(), FName("EnergyBuilding")));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
	}
	for (int i = 0; i < Houses; i++)
	{
		auto building = Cast<UBuilding>(NewObject<UHouseBuilding>(UHouseBuilding::StaticClass(), FName("HouseBuilding")));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
	}
	for (int i = 0; i < FoodBuildings; i++)
	{
		auto building = Cast<UBuilding>(NewObject<UFoodBuilding>(UFoodBuilding::StaticClass(), FName("FoodBuilding")));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
	}
}
