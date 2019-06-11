#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EconomyManager.h"
#include "GameTickManager.h"
#include "ToolbarActor.generated.h"


UCLASS()
class PGTPROJECT_API AToolbarActor : public AActor
{
	GENERATED_BODY()
	
public:

	/**
	 * @brief Construct a new AToolbarActor object
	 * 
	 */
	AToolbarActor();

	/**
	 * @brief Get the Energy object
	 * 
	 * @return int 
	 */
	int getEnergy();

	/**
	 * @brief Get the Minerals object
	 * 
	 * @return int 
	 */
	int getMinerals();
	/**
	 * @brief Get the Money object
	 * 
	 * @return int 
	 */
	int getMoney();

	/**
	 * @brief Get the Population object
	 * 
	 * @return int 
	 */
	int getPopulation();

	/**
	 * @brief Get the Food object
	 * 
	 * @return int 
	 */
	int getFood();

	/**
	 * @brief Get the Minerals Gain object
	 * 
	 * @return int 
	 */
	int getMineralsGain();

	/**
	 * @brief Get the Money Gain object
	 * 
	 * @return int 
	 */
	int getMoneyGain();

	/**
	 * @brief Get the Food Gain object
	 * 
	 * @return int 
	 */
	int getFoodGain();

protected:
	/**
	 * @brief 
	 * 
	 */
	virtual void BeginPlay() override;
	int currentTool;
	int currentMode;

private:
	AEconomyManager* _econ_manager;

public:	

	/**
	 * @brief 
	 * 
	 * @param DeltaTime 
	 */
	virtual void Tick(float DeltaTime) override;
	
	AGameTickManager* GameTickManager;
};
