#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlateBasics.h"
#include "GameHUD.generated.h"

/**
 * @brief Widget component to main UI structure
 * 
 */
class MainGraphics;

UCLASS()
/**
 * @class AGameHUD
 * @brief 
 * 
 */
class PGTPROJECT_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
	public:
		// SafePointer to main UI structure
		TSharedPtr<MainGraphics> _mainWidget;

		/**
		 * @brief Executed once gameplay started, called in .cpp
		 * 
		 */
		void BeginPlay();
};
