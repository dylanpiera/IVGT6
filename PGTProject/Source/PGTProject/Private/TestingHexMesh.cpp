// Fill out your copyright notice in the Description page of Project Settings.

#include "TestingHexMesh.h"
#include "HexActor.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "math.h"
#include "HexActorGraphics.h"

// Sets default values
ATestingHexMesh::ATestingHexMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestingHexMesh::BeginPlay()
{
	HexActorGraphics graphics;

	graphics.GetHeight();
	FVector h = graphics.MeshSize;
	float r = graphics.Radius;

	Super::BeginPlay();
//	FVector loc1 = Position(r, h.Y, 0, 0);
	FVector loc1(0, 0, 0);
	FRotator Rotation(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	AHexActor* a = GetWorld()->SpawnActor<AHexActor>(loc1, Rotation, SpawnInfo);
	
	/*
	FVector c =	a->GetMeshSize();
	UE_LOG(LogTemp, Warning, TEXT("X = %f"), float(c.X));
	UE_LOG(LogTemp, Warning, TEXT("Y = %f"), float(c.Y));
	UE_LOG(LogTemp, Warning, TEXT("Z = %f"), float(c.Z));
	*/

	//FVector loc2 = Position(r, h.Y, 0, 1);
	FVector loc2(h.X - h.Y / FMath::Sqrt(12), h.Y / 2.f, 0);
	FRotator Rotation2(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo2;
	AHexActor* b = GetWorld()->SpawnActor<AHexActor>(loc2, Rotation2, SpawnInfo2);

}

FVector ATestingHexMesh::Position(float radius, float height, int column, int row)
{
	float WIDTH_MULTIPLIER = FMath::Sqrt(3) / 2;

//	float HEIGHT = radius * 2.f;
	float HEIGHT = height;
	float width = WIDTH_MULTIPLIER * HEIGHT;

	float horiz = width;
	float vert = HEIGHT * 0.75f;

	return FVector(
		horiz * (column + row / 2.f),
		vert * row,
		0
	);
}

// Called every frame
void ATestingHexMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

