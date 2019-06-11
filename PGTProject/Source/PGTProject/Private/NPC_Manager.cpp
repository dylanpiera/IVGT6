// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_Manager.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

// Sets default values
ANPC_Manager::ANPC_Manager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	i = 0;
	_controllerIsBusy = false;
}

// Called when the game starts or when spawned
void ANPC_Manager::BeginPlay()
{
	Super::BeginPlay();
	FindHexGridManager();

	Test();
}

// Called every frame
void ANPC_Manager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*
	if(_buildersList.size() > 0 && !_controllerIsBusy) {
		ANPC_Character* builder = _buildersList.at(i);
		if(builder->GetBuilderState() == EWorkState::Walking)
		{
			_controllerIsBusy = true;
			builder->MoveToNextTile();
		}
	}*/
}

ANPC_Character* ANPC_Manager::SpawnBuilder()
{
	if(BuilderToSpawn)
	{
		UWorld* world = GetWorld();
		if(world)
		{
			FActorSpawnParameters spawnParams;
			spawnParams.Owner = this;

			ANPC_Character* newBuilder = world->SpawnActor<ANPC_Character>(BuilderToSpawn, FVector::ZeroVector, FRotator::ZeroRotator, spawnParams);
		
			_buildersList.push_back(newBuilder);

			return newBuilder;
		}
	}
	return NULL;
}

void ANPC_Manager::DeleteBuilder()
{
	if(_buildersList.size() > 0)
	{
		ANPC_Character* builder = _buildersList.back();
		builder->Destroy();
		_buildersList.pop_back();
	}
}

// Get reference to HexGridManager
void ANPC_Manager::FindHexGridManager() {
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AHexGridManager::StaticClass(),
		FoundActors);
	if (FoundActors.Num() > 0) {
		_hexGridManager = Cast<AHexGridManager>(FoundActors[0]);
	}
}

void ANPC_Manager::Test() 
{
	ANPC_Character* myBuilder = SpawnBuilder();
	ANPC_Character* myBuilder2 = SpawnBuilder();
	AHexActor* tile = Cast<AHexActor>(_hexGridManager->_tiles.at(30));
	AHexActor* tile2 = _hexGridManager->_tiles.at(10);
	myBuilder->AssignTask(tile);
	myBuilder2->AssignTask(tile2);
}

/*
void ANPC_Manager::UpdateIter()
{
	if(i + 1 < _buildersList.size()) {
		i = i + 1;
	} else {
		i = 0;
	}
	_controllerIsBusy = false;
}
*/