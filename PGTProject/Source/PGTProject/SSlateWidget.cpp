#include "SSlateWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"
#include "EconomyManager.h"
#include <string>

//Already given upon creation, needs to surround Construct
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

/*
 * \brief
 * Creates elements on the the HUD
 * \params
 */
void SSlateWidget::Construct(const FArguments& InArgs)
{
	//Retrieve argument
	_ownerHUD = InArgs._OwnerHUDArg;

	//temporary values
	int energy = 0;
	int materials = 0;
	int money = 0;
	int population = 0;
	int gain = 0;

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
		//Resource values
		+ SOverlay::Slot()
		.VAlign((VAlign_Top))
		[
			//Energy
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))			
			.Text(FText::FromString(TEXT("Energy")))
			]
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(energy))
			]
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(gain))
			]
			//Materials
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::FromString(TEXT("Materials")))
			]
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_materialsValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(materials))				
			]
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(gain))
			]
			//Money
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::FromString(TEXT("Money")))
			]
			+ SHorizontalBox::Slot()
			[
			SNew(STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(money))
			]
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(gain))
			]
			//Population
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::FromString(TEXT("Population")))
			]
			+ SHorizontalBox::Slot()
			[
			SNew(STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(population))
			]
			+ SHorizontalBox::Slot()
			[
			SAssignNew(_energyValue, STextBlock)
			.ColorAndOpacity(FLinearColor::Green)
			.Font(FSlateFontInfo("Arial", 24))
			.Text(FText::AsNumber(gain))
			]
		]
	];
}
//Already given upon creation, needs to go immediately after Construct
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

/*
 * \brief
 * Test function for the button of type FReply
 */
FReply SSlateWidget::buttonTest()
{
	//Add event here

	//Test event that shows debug message in-game
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Button Clicked"));

	//Return Handled() to basically break, use Unhandled() if it needs to continue
	return FReply::Handled();
}
