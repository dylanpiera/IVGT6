#pragma once

#include "CoreMinimal.h"
#include "HexActor.h"
#include "GameFramework/Actor.h"
#include "HexGridManager.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API AHexGridManager : public AActor
{
	GENERATED_BODY()
	
public:	
	/**
	 * @brief Construct a new AHexGridManager object
	 * 
	 */
	AHexGridManager();

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
	 */
	void GenerateGrid();

	/**
	 * @brief 
	 * 
	 */
	void LogGrid() const;

	const int mapsize = 32;

	/**
	 * @brief 
	 * 
	 */
	AHexActor::Hex *hexes[32][32];

	/**
	 * @brief Get the Hex At object
	 * 
	 * @param x 
	 * @param y 
	 * @return AHexActor::Hex* 
	 */
	AHexActor::Hex* GetHexAt(int x, int y) { return hexes[x][y]; }

};
