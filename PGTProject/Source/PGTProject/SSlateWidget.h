#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Slate.h"
#include "GameHUD.h"

class PGTPROJECT_API SSlateWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SSlateWidget)
	{}

	//Add new argument called OwnerHUDArg
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

private:

	//Pointer to parent HUD, Weak allows to control HUD elsewhere
	TWeakObjectPtr<class AGameHUD> _ownerHUD;
};
