// Fill out your copyright notice in the Description page of Project Settings.

#include "ToolbarGraphics.h"
#include "SlateOptMacros.h"
#include "Engine.h"

//Already given upon creation, needs to surround Construct
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void ToolbarGraphics::Construct(const FArguments& InArgs)
{
	// Retrieve arguments
	_ownerHUD = InArgs._OwnerHUDArg;

	// Define text font
	FString ArialFontPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Fonts/Arial.ttf";
	ArialFont = FSlateFontInfo(ArialFontPath, 20);

	// Define text style for button components
	FTextBlockStyle StyleRef;
	StyleRef.SetFont(FSlateFontInfo(ArialFontPath, 16));
	StyleRef.ColorAndOpacity = FLinearColor::White;

	// Get background image for toolbar
	FString BackgroundImagePath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/BlackBackground.png";

	// Get icons
	FString Road_IconPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/Road_Icon.png";
	FString Building_IconPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/Building_Icon.png";

	FString Road1_IconPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/Road_Icon_1.png";
	FString Building1_IconPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/Building_Icon_1.png";
	FString Building2_IconPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/Building_Icon_2.png";
	FString Building3_IconPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/Building_Icon_3.png";

	FString ImageFramePath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/Image_Frame.png";

	// Close toolbar view panel
	IsOpenToolbarViewPanel = false;

	// Interface
	ChildSlot
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
	[
		// Toolbar
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Center)
		.Padding(FMargin(0, 0, 0, 10))
		[
			// Toolbar View Box
			SNew(SBox)
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			.Visibility(this, &ToolbarGraphics::GetToolbarViewVisibility)
			[
				// Background Image
				SNew(SBorder)
				.BorderBackgroundColor(FLinearColor(56, 56, 56, 0.7f))
				.BorderImage(new FSlateDynamicImageBrush(FName(*BackgroundImagePath), FVector2D(10, 10)))
				[
					SNew(SHorizontalBox)
					// Roads Section
					+ SHorizontalBox::Slot()
					.Padding(FMargin(10, 10))
					[
						// Road Options
						SNew(SUniformGridPanel)
						.SlotPadding(FMargin(5.0f))
						.Visibility(this, &ToolbarGraphics::GetSectionVisibility, RoadsSection)
						// Road 1
						+ SUniformGridPanel::Slot(0, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*Road1_IconPath), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SNew(SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectRoad, RoughRoad)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, RoughRoad)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
					]
					// Buildings Section
					+ SHorizontalBox::Slot()
					.Padding(FMargin(10, 10))
					[
						// Building Options
						SNew(SUniformGridPanel)
						.SlotPadding(FMargin(5.0f))
						.Visibility(this, &ToolbarGraphics::GetSectionVisibility, BuildingsSection)
						// Building 1
						+ SUniformGridPanel::Slot(0, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*Building1_IconPath), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SNew(SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectBuilding, EnergyBuilding)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, EnergyBuilding)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
						// Building 2
						+ SUniformGridPanel::Slot(1, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*Building2_IconPath), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SNew(SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectBuilding, MineralsBuilding)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, MineralsBuilding)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
						// Building 3
						+ SUniformGridPanel::Slot(2, 0)
						[
							SNew(SVerticalBox)
							+ SVerticalBox::Slot()
							[
								SNew(SOverlay)
								+ SOverlay::Slot()
								[
									SNew(SImage)
									.Image(new FSlateDynamicImageBrush(FName(*Building3_IconPath), FVector2D(100, 100)))
								]
								+ SOverlay::Slot()
								[
									SNew(SButton)
									.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
									.OnClicked(this, &ToolbarGraphics::SelectBuilding, MoneyBuilding)
									.DesiredSizeScale(FVector2D(60, 60))
								]
							]
							+ SVerticalBox::Slot()
							[
								SNew(STextBlock)
								.Font(ArialFont)
								.Justification(ETextJustify::Center)
								.Text(this, &ToolbarGraphics::GetOptionTitle, MoneyBuilding)
								.ColorAndOpacity(FLinearColor::White)
							]
						]
					]
				]
			]
		]
		+ SVerticalBox::Slot()
		.VAlign(VAlign_Bottom)
		.HAlign(HAlign_Center)
		.AutoHeight()
		.Padding(FMargin(0, 0, 0, 10))
		[
			// Toolbar Box
			SNew(SBox)
			.VAlign(VAlign_Bottom)
			.HAlign(HAlign_Center)
			[
				SNew(SUniformGridPanel)
				.SlotPadding(FMargin(5.0f))
				// Roads Section
				+ SUniformGridPanel::Slot(0, 0)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SImage)
						.Image(new FSlateDynamicImageBrush(FName(*Road_IconPath), FVector2D(100, 100)))
					]
					+ SOverlay::Slot()
					[
						SNew(SButton)
						.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
						.OnClicked(this, &ToolbarGraphics::ChangeSection, RoadsSection)
					]
				]
				// Buildings Section
				+ SUniformGridPanel::Slot(1, 0)
				[
					SNew(SOverlay)
					+ SOverlay::Slot()
					[
						SNew(SImage)
						.Image(new FSlateDynamicImageBrush(FName(*Building_IconPath), FVector2D(100, 100)))
					]
					+ SOverlay::Slot()
					[
						SNew(SButton)
						.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
						.OnClicked(this, &ToolbarGraphics::ChangeSection, BuildingsSection)
					]
				]
			]
		]
	];
}
//Already given upon creation, needs to go immediately after Construct
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

// Basic text function (FIXME: create content for sections, instead of just a text)
FText ToolbarGraphics::GetInfoText() const
{
	FString Result = TEXT("Content");
	return FText::FromString(Result);
}

FText ToolbarGraphics::GetOptionTitle(OptionSections OptionIndex) const
{
	FString OptionName = OptionsTitles[OptionIndex];
	return FText::FromString(OptionName);
}

FReply ToolbarGraphics::SelectRoad(OptionSections Index) {

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Selecting road"));
	UE_LOG(LogTemp, Warning, TEXT("Selecting road: %d"), Index);

	return FReply::Handled();
}

FReply ToolbarGraphics::SelectBuilding(OptionSections Index) {

	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("Selecting building"));
	UE_LOG(LogTemp, Warning, TEXT("Selecting building: %d"), Index);

	return FReply::Handled();
}

// Change which section is selected
FReply ToolbarGraphics::ChangeSection(ToolbarSections Index)
{
	if(CurrentSection == Index && IsOpenToolbarViewPanel) // If section is opened, close it
	{
		IsOpenToolbarViewPanel = false;
	}
	else { // If changing section or no section is open, open new section
		CurrentSection = Index;
		IsOpenToolbarViewPanel = true;
	}

	return FReply::Handled();
}

// Update which section should be visible
EVisibility ToolbarGraphics::GetSectionVisibility(ToolbarSections Index) const
{
	bool SectionVisibility = false;
	if (Index == CurrentSection) {
		SectionVisibility = true;
	}
	
	return SectionVisibility ? EVisibility::Visible : EVisibility::Collapsed;
}

// Get toolbar view panel visibility
EVisibility ToolbarGraphics::GetToolbarViewVisibility() const
{
	return IsOpenToolbarViewPanel ? EVisibility::Visible : EVisibility::Hidden;
}

// Get section name based on index (section names are predefined on header)
FText ToolbarGraphics::GetSectionTitle(ToolbarSections Index) const
{
	FString SectionName = SectionsTitles[Index];
	return FText::FromString(SectionName);
}

/*
SAssignNew(InfoText_1, STextBlock)
.Font(ArialFont)
.Justification(ETextJustify::Left)
.Text(this, &ToolbarGraphics::GetInfoText)
.ColorAndOpacity(FLinearColor::Blue)
.Visibility(this, &ToolbarGraphics::GetSectionVisibility, 0)


*/