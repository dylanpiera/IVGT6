#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
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

	//Declaring button function
	FReply buttonTest();

private:

	//Safe pointer to parent HUD
	TWeakObjectPtr<class AGameHUD> _ownerHUD;

	//Declaring button
	TSharedPtr<SButton> _colourButton;
};