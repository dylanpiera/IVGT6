#pragma once
#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SlateBasics.h"
#include "GameHUD.generated.h"

class MainGraphics;

UCLASS()
class PGTPROJECT_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
	public:
		//SafePointer to Widgets
		TSharedPtr<MainGraphics> _mainWidget;
		//Executed once gameplay started, called in .cpp
		void BeginPlay();
};
