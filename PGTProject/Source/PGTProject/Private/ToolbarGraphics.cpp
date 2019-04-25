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

	// Define background image for toolbar
	FString BackgroundImagePath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/BlackBackground.png";

	// Set section index to access the sections on toolbar
	SectionIndex = 0;

	// Interface
	ChildSlot
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
	[
		// Toolbar Main Box
		SNew(SBox)
		.VAlign(VAlign_Bottom)
		.Padding(FMargin(350, 20))
		[
			// Background Image
			SNew(SBorder)
			.BorderBackgroundColor(FLinearColor(56, 56, 56, 0.7f))
			.BorderImage(new FSlateDynamicImageBrush(FName(*BackgroundImagePath), FVector2D(10, 10)))
			[
				SNew(SVerticalBox)
				// Toolbar Sections
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.Padding(10)
				[
					SNew(SHorizontalBox)
					// First Section
					+ SHorizontalBox::Slot() 
					[
						SAssignNew(_RoadsSectionButton, SButton)
						.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
						.Text(this, &ToolbarGraphics::GetSectionName, 0)
						.OnClicked(this, &ToolbarGraphics::ChangeSection, 0)
						.TextStyle(&StyleRef)
						.DesiredSizeScale(FVector2D(1.5, 2))
					]
					// Second Section
					+ SHorizontalBox::Slot()
					[
						SAssignNew(_BuildingsSectionButton, SButton)
						.ButtonColorAndOpacity(FLinearColor(1, 1, 1, 0.1f))
						.Text(this, &ToolbarGraphics::GetSectionName, 1)
						.OnClicked(this, &ToolbarGraphics::ChangeSection, 1)
						.TextStyle(&StyleRef)
						.DesiredSizeScale(FVector2D(1.5, 2))
					]
				]
				// Toolbar View Space
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.Padding(10)
				[
					SNew(SHorizontalBox)
					// First Section
					+ SHorizontalBox::Slot()
					[
						SAssignNew(InfoText_1, STextBlock)
						.Font(ArialFont)
						.Justification(ETextJustify::Left)
						.Text(this, &ToolbarGraphics::GetInfoText)
						.ColorAndOpacity(FLinearColor::Blue)
						.Visibility(this, &ToolbarGraphics::GetSectionVisibility, 0)
					]
					// Second Section
					+ SHorizontalBox::Slot()
					[
						SAssignNew(InfoText_2, STextBlock)
						.Font(ArialFont)
						.Justification(ETextJustify::Left)
						.Text(this, &ToolbarGraphics::GetInfoText)
						.ColorAndOpacity(FLinearColor::Red)
						.Visibility(this, &ToolbarGraphics::GetSectionVisibility, 1)
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
	return FText::FromString(Result);;
}

// Change which section is selected
FReply ToolbarGraphics::ChangeSection(int Index)
{
	SectionIndex = Index;

	return FReply::Handled();
}

// Update which section should be visible
EVisibility ToolbarGraphics::GetSectionVisibility(int Index) const
{
	bool SectionVisibility = false;
	if (Index == SectionIndex) {
		SectionVisibility = true;
	}
	
	return SectionVisibility ? EVisibility::Visible : EVisibility::Collapsed;
}

// Get section name based on index (section names are predefined on header)
FText ToolbarGraphics::GetSectionName(int Index) const
{
	FString SectionName = (SectionNames[Index]).c_str();
	return FText::FromString(SectionName);
}
