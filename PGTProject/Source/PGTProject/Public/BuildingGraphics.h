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
	
	/**
	 * @brief 
	 * 
	 */
	ABuildingGraphics();

	ADataHolder* holder;

	UStaticMeshComponent* Mesh;

	UStaticMesh* BuildingMesh;

	float growth;

protected:
	
	/**
	 * @brief 
	 * 
	 */
	virtual void BeginPlay() override;

public:	
	
	/**
	 * @brief 
	 * 
	 * @param DeltaTime 
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Sets the BuildingGraphic to the building type specific graphic.
	 * 
	 * @param buildingIndex
	 * @param meshComp
	 */
	void SetBuildingGraphics(OptionSections buildingIndex, UStaticMeshComponent* meshComp);

	/**
	 * @brief 
	 * 
	 * @param buildingIndex 
	 */
	void LoadGraphics(OptionSections buildingIndex);

	/**
	 * @brief 
	 * 
	 */
	void BuildingAnimation();
};
