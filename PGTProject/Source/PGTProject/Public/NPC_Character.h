// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Pathfinding.h"
#include "Constants.h"
#include "Runtime/Core/Public/Math/Vector.h"
#include "NPC_Character.generated.h"

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

	// Move character to a specific world location
	UFUNCTION(BlueprintImplementableEvent, Category = "MoveCharacterEvent")
	void MoveToLocation(const FVector& newLocation);

	// Get builder working state
	EWorkState GetBuilderState();

	// Assing a task to builder
	void AssignTask(AHexActor* buildingTile);

	// Move to next tile in path to building
	void MoveToNextTile();

	// Set building world space location
	void SetBuildingLocation(FVector aux);

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
	// Reference to NPCManager
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
	// Use pathfinding to find path to building
	void FindPathToTile(AHexActor* tile);
	// Get next tile for NPC to move to
	void GetNextTileOnPath();
	// Get reference to HexGridManager
	void FindNPCManager();
};