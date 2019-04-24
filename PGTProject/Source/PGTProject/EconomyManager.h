#pragma once

#include "GameFramework/Actor.h"
#include "EconomyManager.generated.h"

UCLASS()
class PGTPROJECT_API AEconomyManager : public AActor
{
	GENERATED_BODY()

public:
	/**
	 * \brief
	 * Stores the resources the game requires
	 */
	struct Resources
	{
		int _energy;
		int _materials;
		int _money;

		explicit Resources(const int energy = 0, const int materials = 0, const int money = 0) : _energy(energy), _materials(materials), _money(money) { }
	};

	Resources resources;
};
