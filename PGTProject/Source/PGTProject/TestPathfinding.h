#pragma once

// (UPDATE) Testing class

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestPathfinding.generated.h"

UCLASS()
/**
 * @brief 
 * 
 */
class PGTPROJECT_API ATestPathfinding : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestPathfinding();

protected:
/**
 * @brief Calling pathfinding test 
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
