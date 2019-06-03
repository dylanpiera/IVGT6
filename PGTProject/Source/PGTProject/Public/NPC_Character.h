// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Constants.h"
#include "NPC_Character.generated.h"

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
	void AssignTask(FVector buildingLocation);

private:
	// Working state
	EWorkState _state;

	// Next building location
	FVector _buildingLocation;

	// Next tile to move to
	FVector _goalLocation;

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
};
