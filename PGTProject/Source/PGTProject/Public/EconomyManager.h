// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
		int _minerals;
		int _money;

		explicit Resources(const int energy = 0, const int materials = 0, const int money = 0) : _energy(energy), _minerals(materials), _money(money) { }
	};

	Resources resources;
};
