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
	int minerals = 0;
	int money = 0;
	int population = 0;
	int gain = 0;
	int hour = 12;
	int minute = 36;

	//Location reference to the image
	FString energyImagePath = FPaths::ProjectContentDir() / TEXT("Assets/energyIcon.png");
	FString mineralsImagePath = FPaths::ProjectContentDir() / TEXT("Assets/mineralIcon.png");
	FString moneyImagePath = FPaths::ProjectContentDir() / TEXT("Assets/moneyIcon.png");
	FString populationImagePath = FPaths::ProjectContentDir() / TEXT("Assets/populationIcon.png");

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
		/*
		 * \brief Shows resources in top left corner in the order of Name-currentValue-valueGain/Loss
		 * \TODO reference to actual variables in the game
		 */
		+ SOverlay::Slot()
		.VAlign((VAlign_Top))
		[
			//Energy
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			//Adjusts width to the element size
			.AutoWidth()
			[
				/*SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))			
				.Text(FText::FromString(TEXT("Energy")))*/
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*energyImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_energyValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(energy))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(gain))
			]
			//Minerals
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				/*SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::FromString(TEXT("Minerals")))*/
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*mineralsImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_materialsValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(minerals))				
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(gain))
			]
			//Money
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				/*SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::FromString(TEXT("Money")))*/
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*moneyImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_moneyValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(money))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(gain))
			]
			//Population
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				/*SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::FromString(TEXT("Population")))*/
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*populationImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_populationValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(population))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(gain))
			]
		]
		/*
		 * \brief Timer in the upper right corner
		 * \TODO link Game tick
		 */
		+ SOverlay::Slot()
		.VAlign((VAlign_Top))
		.HAlign(HAlign_Right)
		[
			//Hours
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(hour))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::FromString(TEXT(":")))
			]
			//Minutes
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(0.0f, 0.0f, 10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::Green)
				.Font(FSlateFontInfo("Arial", 24))
				.Text(FText::AsNumber(minute))
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
