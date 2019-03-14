#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlateBasics.h"
#include "GameHUD.generated.h"

// Predeclaration of SlateWidget
class SSlateWidget;

UCLASS()
class PGTPROJECT_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
	public:
		//Reference to an SCompoundWidget, TSharedPtr adds to the refcount of UIWidget
		//UIWidget will not self-destruct as long as refcount > 0. refcount will be (refcout-1) if HUD is destroyed.
		TSharedPtr<SSlateWidget> _uiWidget;
		
		void BeginPlay();
};
