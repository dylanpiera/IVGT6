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
