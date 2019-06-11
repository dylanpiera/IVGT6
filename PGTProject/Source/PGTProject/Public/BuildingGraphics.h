#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToolbarGraphics.h"
#include "BuildingGraphics.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API ABuildingGraphics : public AActor
{
	GENERATED_BODY()
	
public:	
	
	/**
	 * @brief Constructs the BuildingGraphics 
	 * 
	 */
	ABuildingGraphics();

	ADataHolder* holder;

	UStaticMeshComponent* Mesh;

	UStaticMesh* BuildingMesh;

	float growth;

protected:
	
	/**
	 * @brief Override BeginPlay function. Find the ADataHolder Actor in the game world.
	 * 
	 */
	virtual void BeginPlay() override;

public:	
	
	/**
	 * @brief Standard Unreal Tick function.
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
	 * @brief Used to set parameter for SetBuildingGraphics
	 * 
	 * @param buildingIndex 
	 */
	void LoadGraphics(OptionSections buildingIndex);

	/**
	 * @brief Slowly increments the Z-axis in the to visualize a "growth", Runs in the Tick function
	 * 
	 */
	void BuildingAnimation();
};
