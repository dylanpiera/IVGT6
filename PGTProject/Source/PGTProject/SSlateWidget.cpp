#include "SSlateWidget.h"
#include "SlateOptMacros.h"

//Needed for location macro LOCTEXT
#define LOCTEXT_NAMESPACE "SSlateWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

/*
 * Creates elements on the the HUD
 */
void SSlateWidget::Construct(const FArguments& InArgs)
{
	//Retrieve argument
	_ownerHUD = InArgs._OwnerHUDArg;

	//Fill screen with slot which allows to to add different things to the HUD
	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
	[
		//Creates new overlay in slot, each + SOverlay adds a new slot that contains a component
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Center)
		.HAlign(HAlign_Center)
		[
			//Adds button
			SNew(SButton)
			.ButtonColorAndOpacity(FLinearColor::Black)
			.ButtonColorAndOpacity(FLinearColor::Blue)
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

//needs to be undefined after creation
#undef LOCTEXT_NAMESPACE