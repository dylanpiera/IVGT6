#include "MainGraphics.h"
#include "SlateOptMacros.h"
#include "Engine.h"

//Already given upon creation, needs to surround Construct
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void MainGraphics::Construct(const FArguments& InArgs)
{
	// Retrieve arguments
	_ownerHUD = InArgs._OwnerHUDArg;

	// Interface
	ChildSlot
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		SNew(SHorizontalBox)
		+ SHorizontalBox::Slot()
		[
			SAssignNew(_ownerEconomyBar, SSlateWidget)
			.OwnerHUDArg(_ownerHUD)
		]
		+ SHorizontalBox::Slot()
		[
			SAssignNew(_ownerToolbar, ToolbarGraphics)
			.OwnerHUDArg(_ownerHUD)
		]
	];
}
//Already given upon creation, needs to go immediately after Construct
END_SLATE_FUNCTION_BUILD_OPTIMIZATION