#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MouseController.generated.h"

UCLASS()
/**
 * @brief Makes mouse visible in-game
 * 
 */
class PGTPROJECT_API AMouseController : public APlayerController
{
	GENERATED_BODY()

	/**
	 * @brief Construct a new AMouseController object
	 * 
	 */
	AMouseController()
	{
		bShowMouseCursor = true;
	}
	
};
