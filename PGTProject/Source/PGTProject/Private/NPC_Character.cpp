// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "NPC_Manager.h"
#include "HexActor.h"
#include "Engine/Engine.h"
#include "Runtime/Core/Public/Math/Vector.h"


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

	_buildingLocation = FVector(0, 0, 0);
	// Pathfinding settings
	FindNPCManager();
	if(_npcManager->_hexGridManager->_tiles.size() > 0) {
		_currentTile = _npcManager->_hexGridManager->_tiles.at(0); // Get first tile 
		//FVector currentTileLocation = _currentTile->GetActorLocation();
		//FVector currentTileLocation = _currentTile->GetScreenSpaceLocationForHex(_currentTile->hex);
		FVector aux = AHexActor::GetScreenSpaceLocation(_currentTile->hex);
		_goalLocation = FVector(aux.X, aux.Y, aux.Z);
		aux.Z += 100;
		SetActorLocation(aux, false);
	}
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
			_currentTile = _goalTile;

			if(ReachedBuilding()) {
				StartWorking();
			} else {
				
				MoveToNextTile();
			}

			//_npcManager->UpdateIter();
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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Reached Location!"));
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

void ANPC_Character::AssignTask(AHexActor* buildingTile)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Assign task!"));

	SetBuildingLocation(buildingTile->GetActorLocation());
	//AHexActor::GetScreenSpaceLocation(buildingTile->hex);
	//UE_LOG(LogTemp, Warning, TEXT("TRY 1"));
	//_buildingLocation = buildingTile->GetActorLocation();
	//FVector aux = AHexActor::GetScreenSpaceLocation(buildingTile->hex);
	//UE_LOG(LogTemp, Warning, TEXT("aux %f %f %f"), aux.X, aux.Y, aux.Z);
	//_buildingLocation = FVector(aux.X, aux.Y, aux.Z);

	//SetBuildingLocation(aux);
	//UE_LOG(LogTemp, Warning, TEXT("TRY 2"));
	//_buildingLocation = AHexActor::GetScreenSpaceLocation(buildingTile->hex);
	//UE_LOG(LogTemp, Warning, TEXT("TRY 3"));
	//_buildingLocation = buildingTile->GetScreenSpaceLocationForHex(buildingTile->hex);
	
	// Start moving towards building
	FindPathToTile(buildingTile);
	SetBuilderState(EWorkState::Walking);
	MoveToNextTile();
}

void ANPC_Character::SetBuildingLocation(FVector aux)
{
	float X = aux.X;
	float Y = aux.Y;
	float Z = aux.Z;
	_buildingLocation.Set(X,Y,Z);
}

void ANPC_Character::StartWorking()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Start working!"));
	SetBuilderState(EWorkState::Working);
}

void ANPC_Character::FindPathToTile(AHexActor* tile)
{
	AHexActor* startTile = _currentTile;
	AHexActor* endTile = tile;
	
	_pathToBuilding.clear();
	_pathToBuilding = _pathfinder.AStarPathfinding(startTile, endTile);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Found PATH!"));
}

void ANPC_Character::GetNextTileOnPath()
{
	if(_pathToBuilding.size() > 0) {
		_goalTile = _pathToBuilding.front();
		_pathToBuilding.pop_front();
	}

	//_goalLocation = _goalTile->GetScreenSpaceLocationForHex(_goalTile->hex);
	//_goalLocation = _goalTile->GetActorLocation();
	FVector aux = AHexActor::GetScreenSpaceLocation(_goalTile->hex);
	_goalLocation = FVector(aux.X, aux.Y, aux.Z);
}

void ANPC_Character::MoveToNextTile()
{
	GetNextTileOnPath();
	MoveToLocation(_goalLocation);
}

// Get reference to HexGridManager
void ANPC_Character::FindNPCManager() {
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		ANPC_Manager::StaticClass(),
		FoundActors);
	if (FoundActors.Num() > 0) {
		_npcManager = Cast<ANPC_Manager>(FoundActors[0]);
	}
}
