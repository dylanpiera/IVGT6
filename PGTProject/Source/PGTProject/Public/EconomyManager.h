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
	// Sets default values for this actor's properties
	AEconomyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

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
