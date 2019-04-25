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
	TWeakObjectPtr<class AToolbarActor> _toolbarActor;

	//Declare buttons
	TSharedPtr<SButton> _colourButton;

	TSharedPtr<STextBlock> _energyValue;
	TSharedPtr<STextBlock> _materialsValue;
	TSharedPtr<STextBlock> _moneyValue;
	TSharedPtr<STextBlock> _populationValue;
};
