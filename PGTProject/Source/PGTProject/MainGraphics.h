#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "SSlateWidget.h"
#include "ToolbarGraphics.h"

class PGTPROJECT_API MainGraphics : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(MainGraphics) {}

	// Add new argument called OwnerHUDArg
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	SLATE_END_ARGS()

	// Constructs this widget with InArgs
	void Construct(const FArguments& InArgs);

private:

	//Safe pointer to parent HUD
	TWeakObjectPtr<class AGameHUD> _ownerHUD;
	TSharedPtr<ToolbarGraphics> _ownerToolbar;
	TSharedPtr<SSlateWidget> _ownerEconomyBar;
};
