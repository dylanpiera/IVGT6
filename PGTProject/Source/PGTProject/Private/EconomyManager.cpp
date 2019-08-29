#include "EconomyManager.h"
#include "MineralBuilding.h"
#include "EnergyBuilding.h"
#include "HouseBuilding.h"
#include "FoodBuilding.h"
#include <ActiveState.h>

//Energy variables
int energyBldGain = 50;
int mineralBldEnergyCost = 50;
int houseEnergyCost = 10;
int foodBldEnergyCost = 5;

//Sets initial values
void AEconomyManager::InitResources()
{
	resources._energy = 600;
	resources._population = 11;
	resources._minerals = 150;
	resources._money = 200;
	resources._food = 0;
}

//For each resource
void AEconomyManager::BeginPlay()
{
	for (int i = 0; i < EnergyBuildings; i++)
	{
		auto building = Cast<UBuilding>(NewObject<UEnergyBuilding>(UEnergyBuilding::StaticClass()));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
		resources._energy += energyBldGain;
	}
	for (int i = 0; i < MineralBuildings; i++)
	{
		auto building = Cast<UBuilding>(NewObject<UMineralBuilding>(UMineralBuilding::StaticClass()));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
        resources._energy -= mineralBldEnergyCost;
	}
	for (int i = 0; i < Houses; i++)
	{
		auto building = Cast<UBuilding>(NewObject<UHouseBuilding>(UHouseBuilding::StaticClass()));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
        resources._energy -= houseEnergyCost;
	}
	for (int i = 0; i < FoodBuildings; i++)
	{
		auto building = Cast<UBuilding>(NewObject<UFoodBuilding>(UFoodBuilding::StaticClass()));
		building->SetState(new ActiveState());
		ActiveBuildings.Add(building);
        resources._energy -= foodBldEnergyCost;
	}
}
