// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingHexMesh.h"
#include "HexActor.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values
ATestingHexMesh::ATestingHexMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestingHexMesh::BeginPlay()
{
	Super::BeginPlay();
	FVector Location(0.0f, 0.0f, 100.0f);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	AHexActor* a = GetWorld()->SpawnActor<AHexActor>(Location, Rotation, SpawnInfo);
	
	FVector c =	a->GetMeshSize();
	UE_LOG(LogTemp, Warning, TEXT("X = %f"), float(c.X));
	UE_LOG(LogTemp, Warning, TEXT("Y = %f"), float(c.Y));
	UE_LOG(LogTemp, Warning, TEXT("Z = %f"), float(c.Z));

	FVector Location2(Location.X + (c.X), Location.Y, Location.Z);
	FRotator Rotation2(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo2;
	AHexActor* b = GetWorld()->SpawnActor<AHexActor>(Location2, Rotation2, SpawnInfo2);


}

void CreateTiles() {

}

// Called every frame
void ATestingHexMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

