#include "SSlateWidget.h"
#include "SlateOptMacros.h"
#include "Engine.h"
#include "EconomyManager.h"
#include "ToolbarActor.h"
#include "GameTickManager.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Components/ActorComponent.h"
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
	_toolbarActor = InArgs._ToolbarActorArg;

	//temporary values
	int gain = 0;

	//Location reference to project files
	const FString energyImagePath = FPaths::ProjectContentDir() / TEXT("Assets/energyIcon.png");
	const FString mineralsImagePath = FPaths::ProjectContentDir() / TEXT("Assets/mineralIcon.png");
	const FString moneyImagePath = FPaths::ProjectContentDir() / TEXT("Assets/moneyIcon.png");
	const FString populationImagePath = FPaths::ProjectContentDir() / TEXT("Assets/populationIcon.png");
	const FSlateFontInfo Raleway = FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("Slate/Fonts/Raleway-Bold.ttf"), 42);


	//Fill screen with slot which allows to to add different things to the HUD
	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
	[
		//Creates new overlay in slot, each + SOverlay adds a new slot that contains a component
		SNew(SOverlay)
		/*
		 * \brief Shows resources in top left corner in the order of Name-currentValue-valueGain/Loss
		 * 
		 */

		+SOverlay::Slot()
		.VAlign((VAlign_Top))
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SColorBlock)
				.Color(FLinearColor::Black)
				.Size(FVector2D(2560, 72))
			]
		]


		+ SOverlay::Slot()
		.VAlign((VAlign_Top))
		[
			SNew(SHorizontalBox)
			//Energy
			+SHorizontalBox::Slot()
			//Adjusts width to the element size
			.AutoWidth()
			[
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*energyImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_energyValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->getEnergy()); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text(FText::AsNumber(gain))
			]
			//Minerals
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*mineralsImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_materialsValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->getMinerals()); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text(FText::AsNumber(gain))
			]
			//Money
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*moneyImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_moneyValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->getMoney()); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text(FText::AsNumber(gain))
			]
			//Population
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(SImage)
				.Image(new FSlateDynamicImageBrush(FName(*populationImagePath), FVector2D(64, 64)))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SAssignNew(_populationValue, STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->getPopulation()); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
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
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->GameTickManager->currentHour); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text(FText::FromString(TEXT("h")))
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::FromString(_toolbarActor->GameTickManager->dayName); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->GameTickManager->currentDay + 1); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::FromString(_toolbarActor->GameTickManager->monthName); })
			]
			+SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->GameTickManager->currentYearFirst); })
			]
			+ SHorizontalBox::Slot()
			.AutoWidth()
			[
				SNew(STextBlock)
				.Margin(FMargin(0.0f, 0.0f, 10.0f, 0.0f))
				.ColorAndOpacity(FLinearColor::White)
				.Font(Raleway)
				.Text_Lambda([this]()->FText {return FText::AsNumber(_toolbarActor->GameTickManager->currentYearSecond); })
			]
		]
	];
}
//Already given upon creation, needs to go immediately after Construct
END_SLATE_FUNCTION_BUILD_OPTIMIZATION