// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToolbarGraphics.h"
#include "BuildingGraphics.generated.h"

UCLASS()
class PGTPROJECT_API ABuildingGraphics : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingGraphics();

	ADataHolder* holder;

	UStaticMeshComponent* Mesh;

	UStaticMesh* BuildingMesh;

	float growth;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetBuildingGraphics(OptionSections buildingIndex, UStaticMeshComponent* meshComp);
	void LoadGraphics(OptionSections buildingIndex);

	void BuildingAnimation();
};
