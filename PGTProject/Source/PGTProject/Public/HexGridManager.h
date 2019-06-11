#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "GameFramework/Actor.h"
#include "HexGridManager.generated.h"


UCLASS()
/**
 * @brief The manager for our Axial-aligned Hex Grid.
 * 
 * Holds all logic for generating and accessing the axial-coordinate based Hex-Grid. 
 */
class PGTPROJECT_API AHexGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	/**
	 * @brief Construct a new AHexGridManager object
	 * 
	 * Sets the default values.
	 */
	AHexGridManager();

protected:
	/**
	 * @brief Initializes the actor once it is created.
	 */
	virtual void BeginPlay() override;

public:	

	/**
	 * @brief Unreal Actor Implementation
	 * 
	 */
	virtual void Tick(float DeltaTime) override;

	/**
	 * @brief Generates a hexgrid
	 * 
	 * Generates a Hexgrid with a dimension of 32x32 
	 */
	void GenerateGrid();

	/**
	 * @brief Outputs the grid generation to the Unreal Console
	 */
	void LogGrid() const;

	const int mapsize = 32;

	/**
	 * @brief The container of hexes
	 */
	AHexActor::Hex *hexes[32][32];

	/**
	 * @brief Get the Hex based on grid coordinates
	 * 
	 * @param x X-Cooardinate
	 * @param y Y-Cooardinate
	 * @return AHexActor::Hex* A reference to the hex. 
	 */
	AHexActor::Hex* GetHexAt(int x, int y) { return hexes[x][y]; }

};
