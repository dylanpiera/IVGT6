#include "SSlateWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"

//Already given upon creation, needs to surround Construct
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
		//Vertical and Horizontal alignment of slot
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Left)
		[
			//Adds button
			SAssignNew(_colourButton,SButton)
			.ButtonColorAndOpacity(FLinearColor::Black)
			.ButtonColorAndOpacity(FLinearColor::Blue)
			//Call event with OnClicked(this, &YourClassName::yourFunctionName)
			.OnClicked(this, &SSlateWidget::buttonTest)
		]
	];
}
////Already given upon creation, needs to go immediately after Construct
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

//Test function for the button of type FReply
FReply SSlateWidget::buttonTest()
{
	//Add event here

	//Test event that shows debug message in-game
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Button Clicked"));

	//Return Handled() to basically break, use Unhandled() if it needs to continue
	return FReply::Handled();
}
