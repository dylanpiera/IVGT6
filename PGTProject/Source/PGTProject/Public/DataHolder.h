#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Constants.h"
#include "DataHolder.generated.h"

UCLASS()
/**
 * @brief Data Holder class to Get and Set values from and to Actors/Toolbars
 * 
 */
class PGTPROJECT_API ADataHolder : public AActor
{
	GENERATED_BODY()
	
public:	
	/**
	 * @brief Construct a new ADataHolder object
	 * 
	 */
	ADataHolder();

	OptionSections abuilding;

	/**
	 * @brief Set the Building object
	 * 
	 * @param building 
	 */
	void SetBuilding(OptionSections building);
    
	/**
	 * @brief Get the Building object
	 * 
	 * @return OptionSections 
	 */
	OptionSections GetBuilding();

	

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


};
