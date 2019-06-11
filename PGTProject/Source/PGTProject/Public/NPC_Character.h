// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Pathfinding.h"
//#include "HexGridManager.h"
//#include "NPC_Manager.h"
#include "Constants.h"
#include "NPC_Character.generated.h"
#include "Runtime/Core/Public/Math/Vector.h"

class ANPC_Manager;

UCLASS()
class PGTPROJECT_API ANPC_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_Character();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Acess own mesh component
	UPROPERTY(VisibleAnywhere, Category = SkeletalMesh)
	class USkeletalMesh* MeshContainer;
	UPROPERTY(VisibleAnywhere, Category = SkeletalMesh)
	class USkeletalMeshComponent* CharacterMesh;

	//UPROPERTY(EditAnywhere)
	//FVector myNextLocation;

	// Move character to a specific world location
	UFUNCTION(BlueprintImplementableEvent, Category = "MoveCharacterEvent")
	void MoveToLocation(FVector& newLocation);

	// Get builder working state
	EWorkState GetBuilderState();

	// Assing a task to builder
	void AssignTask(AHexActor* buildingTile);

	void MoveToNextTile();

private:
	// Working state
	EWorkState _state;
	// Next building location
	FVector _buildingLocation;
	// Next tile to move to
	FVector _goalLocation;
	// Pathfinding instance
	Pathfinding _pathfinder;
	// Path
	list<AHexActor*> _pathToBuilding;
	// Tiles info
	AHexActor* _currentTile;
	AHexActor* _goalTile;
	// Reference to HexGridManager
	//AHexGridManager* _hexGridManager;
	ANPC_Manager* _npcManager;

	// Modify working state
	void SetBuilderState(EWorkState newState);
	// Load character mesh and attach to this character
	void LoadMesh();
	// Check if builder reached next goal location
	bool ReachedLocation();
	// Check if builder reached final building location
	bool ReachedBuilding();
	// Make builder start work
	void StartWorking();

	void FindPathToTile(AHexActor* tile);

	void GetNextTileOnPath();

	// Get reference to HexGridManager
	//void FindHexGridManager();
	void FindNPCManager();
};
