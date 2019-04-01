#pragma once

// (UPDATE) Testing class

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestPathfinding.generated.h"

UCLASS()
class PGTPROJECT_API ATestPathfinding : public AActor
{
	GENERATED_BODY()
	
public:	
	ATestPathfinding();

protected:
	virtual void BeginPlay() override; // Calling pathfinding test 

public:	
	virtual void Tick(float DeltaTime) override;

};
