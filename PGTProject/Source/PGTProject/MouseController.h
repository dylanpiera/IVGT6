#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MouseController.generated.h"

/**
 * Makes mouse visible in-game
 */
UCLASS()
class PGTPROJECT_API AMouseController : public APlayerController
{
	GENERATED_BODY()

	AMouseController()
	{
		bShowMouseCursor = true;
	}
	
};
