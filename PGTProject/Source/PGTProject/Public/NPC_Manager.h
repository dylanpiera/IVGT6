// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NPC_Character.h"
#include <vector>
#include "HexGridManager.h"
#include "NPC_Manager.generated.h"

using namespace std;

UCLASS()
class PGTPROJECT_API ANPC_Manager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANPC_Manager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Reference to HexGridManager
	AHexGridManager* _hexGridManager;

	// Spawn new builder
	ANPC_Character* SpawnBuilder();

	// Delete oldest builder
	void DeleteBuilder();

	void UpdateIter();
private:
	int i;
	bool _controllerIsBusy;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ANPC_Character> BuilderToSpawn;

	// List to keep track of the existing builders
	vector<ANPC_Character*> _buildersList;

	// Find reference to HexGridManager
	void FindHexGridManager();

	void Test();
};
