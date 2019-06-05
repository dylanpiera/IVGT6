#include "MainGraphics.h"
#include "SlateOptMacros.h"
#include "Engine.h"

//Already given upon creation, needs to surround Construct
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void MainGraphics::Construct(const FArguments& InArgs)
{
	// Retrieve arguments
	_ownerHUD = InArgs._OwnerHUDArg;
	_toolbarActor = InArgs._ToolbarActorArg;
	_dataHolder = InArgs._DataHolderArgs;

	// Interface
	ChildSlot
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		[
			SAssignNew(_ownerEconomyBar, SSlateWidget)
			.OwnerHUDArg(_ownerHUD)
			.ToolbarActorArg(_toolbarActor)
		]
		+ SVerticalBox::Slot()
		[
			SAssignNew(_ownerToolbar, ToolbarGraphics)
			.OwnerHUDArg(_ownerHUD)
			.DataHolderArgs(_dataHolder)
		]
	];
}
//Already given upon creation, needs to go immediately after Construct
END_SLATE_FUNCTION_BUILD_OPTIMIZATION