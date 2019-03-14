#include "SSlateWidget.h"
#include "PGTProject.h"
#include "SlateOptMacros.h"

//Needed for location macro LOCTEXT
#define LOCTEXT_NAMESPACE "SSlateWidget"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SSlateWidget::Construct(const FArguments& InArgs)
{
	//Assign argument to local variable
	_ownerHUD = InArgs._OwnerHUDArg;

	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Top)
		.HAlign(HAlign_Center)
		[
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