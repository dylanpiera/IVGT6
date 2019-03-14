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
		//SafePointer to Widget
		TSharedPtr<SSlateWidget> _uiWidget;
		//Executed once gameplay started, called in .cpp
		void BeginPlay();
};
