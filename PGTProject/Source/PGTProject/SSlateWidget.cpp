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
		//Creates new overlay in slot
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Center)
		[
			//Text block properties in overlay
			SNew(STextBlock)
			.ShadowColorAndOpacity(FLinearColor::Black)
			.ColorAndOpacity(FLinearColor::Red)
			.ShadowOffset(FIntPoint(-1,1))
			.Font(FSlateFontInfo("Verdana", 16))
			.Text(LOCTEXT("HelloSlateText", "Hello Slate!"))
		]
	];
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION

//needs to be undefined after creation
#undef LOCTEXT_NAMESPACE