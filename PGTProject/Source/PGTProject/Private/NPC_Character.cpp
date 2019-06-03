// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_Character.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
ANPC_Character::ANPC_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Configure visual representation
	LoadMesh();

	// Configure builder initial state
	SetBuilderState(EWorkState::Free);
}

// Called when the game starts or when spawned
void ANPC_Character::BeginPlay()
{
	Super::BeginPlay();

	FVector tile = FVector(4000, 4000, 0);
	AssignTask(tile);
}

// Called every frame
void ANPC_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// When builder is moving check movement status
	if(GetBuilderState() == EWorkState::Walking) {
		// If reached building, start working, if not, keep moving
		if(ReachedLocation())
		{
			if(ReachedBuilding()) {
				StartWorking();
			} else {
				//FVector nextTile;
				//MoveToLocation(nextTile);
			}
		}
	}
}

// Called to bind functionality to input
void ANPC_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ANPC_Character::LoadMesh()
{
	// Find and load skeletal mesh
	MeshContainer = LoadObject<USkeletalMesh>(nullptr, TEXT("SkeletalMesh'/Game/AnimStarterPack/UE4_Mannequin/Mesh/SK_Mannequin.SK_Mannequin'"));
	// If mesh was found apply it to this character
	if (MeshContainer) {
		CharacterMesh = GetMesh();
		CharacterMesh->SetSkeletalMesh(MeshContainer);
		FVector MeshScale = FVector(0.5f, 0.5f, 0.5f);
		CharacterMesh->SetWorldScale3D(MeshScale);
	}
}

EWorkState ANPC_Character::GetBuilderState()
{
	return _state;
}

void ANPC_Character::SetBuilderState(EWorkState newState)
{
	_state = newState;
}

bool ANPC_Character::ReachedLocation()
{
	FVector currentLocation = GetActorLocation();
	FVector goal = _goalLocation;

	// Ignore height comparison
	currentLocation.Z = 0;
	goal.Z = 0;
	
	// Check if reached next tile (with a distance tolerance)
	if(currentLocation.Equals(goal, 100.0f))
	{
		return true;
	} else {
		return false;
	}
}

bool ANPC_Character::ReachedBuilding()
{
	FVector currentLocation = GetActorLocation();
	FVector building = _buildingLocation;

	// Ignore height comparison
	currentLocation.Z = 0;
	building.Z = 0;

	// Check if reached final goal: building tile (with a distance tolerance)
	if(currentLocation.Equals(building, 100.0f))
	{
		return true;
	} else {
		return false;
	}
}

void ANPC_Character::AssignTask(FVector buildingLocation)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Assign task!"));
	// Save building location
	_buildingLocation = buildingLocation;
	
	// Start moving towards building
	_goalLocation = _buildingLocation;
	MoveToLocation(_goalLocation);
	SetBuilderState(EWorkState::Walking);
}

void ANPC_Character::StartWorking()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Start working!"));
	SetBuilderState(EWorkState::Working);
}