// Fill out your copyright notice in the Description page of Project Settings.

#include "ToolbarGraphics.h"
#include "SlateOptMacros.h"
#include "Engine.h"

//Already given upon creation, needs to surround Construct
BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void ToolbarGraphics::Construct(const FArguments& InArgs)
{
	//Retrieve argument
	_ownerHUD = InArgs._OwnerHUDArg;

	// Settings: Create Arial Font
	FString ArialFontPath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Fonts/Arial.ttf";
	UE_LOG(LogTemp, Warning, TEXT("font path: %s"), *ArialFontPath);
	ArialFont = FSlateFontInfo(ArialFontPath, 20);

	//FString BackgroundImagePath = "Texture2D'/Game/Assets/UI/Images/BackgroundColores.BackgroundColores'";
	FString BackgroundImagePath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/BlackBackground.png";
	UE_LOG(LogTemp, Warning, TEXT("background path: %s"), *BackgroundImagePath);

	// Set section name index to iterate through predefined series of section names
	SectionIndex = 0;

	FTextBlockStyle StyleRef;
	StyleRef.SetFont(FSlateFontInfo(ArialFontPath, 16));
	StyleRef.ColorAndOpacity = FLinearColor::White;

	// Settings: Create Background Image
	//MyUIResources = FModuleManager::GetModuleChecked<FMyProject>(FName("MyProject")).GetSlateGameResources();
	
	//FString BackgroundImagePath = "Texture2D'/Game/Assets/UI/Images/BackgroundColores.BackgroundColores'";	
	//UTexture2D* backgroundTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(BackgroundImagePath)));

	ChildSlot
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
	[
		// Toolbar
		SNew(SBox)
//		.MaxWidth(_ownerHUD->GetScreenWidth() * 1)
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
				// Toolbar View Section
				+ SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.Padding(10)
				[
					//SAssignNew(ViewSection, SHorizontalBox)

					SNew(SHorizontalBox)
					// First Section
					+ SHorizontalBox::Slot()
					[
						SAssignNew(InfoText, STextBlock)
						.Font(ArialFont)
						.Justification(ETextJustify::Left)
						.Text(this, &ToolbarGraphics::GetInfoText)
						.ColorAndOpacity(FLinearColor::Blue)
						.Visibility(this, &ToolbarGraphics::GetSectionVisibility, 0)
					]
					// Second Section
					+ SHorizontalBox::Slot()
					[
						SAssignNew(InfoText, STextBlock)
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

/*
 * \brief
 * Test function for the button of type FReply
 */
FReply ToolbarGraphics::ChangeSection(int Index)
{
	SectionIndex = Index;

	return FReply::Handled();
}

EVisibility ToolbarGraphics::GetTopPanelVisibility() const
{
//	return _ownerHUD->IsOverlayOpen() ? EVisibility::Hidden : EVisibility::Visible;
	return EVisibility::Visible;
}

EVisibility ToolbarGraphics::GetSectionVisibility(int Index) const
{
	bool SectionVisibility = false;
	if (Index == SectionIndex) {
		SectionVisibility = true;
	}
	
	return SectionVisibility ? EVisibility::Visible : EVisibility::Collapsed;
}

FText ToolbarGraphics::GetInfoText() const
{
	FString Result = TEXT("Content");
	return FText::FromString(Result);;
}

FText ToolbarGraphics::GetSectionName(int Index) const
{
	FString SectionName = (SectionNames[Index]).c_str();
	return FText::FromString(SectionName);
}


const FSlateBrush* ToolbarGraphics::GetImageBrush() const
{
	FString BackgroundImagePath = FString(FPaths::ProjectContentDir()) + "Assets/UI/Images/BlackBackground.png";
	UTexture2D* backgroundTexture = Cast<UTexture2D>(StaticLoadObject(UTexture2D::StaticClass(), NULL, *(BackgroundImagePath)));

	if (backgroundTexture) {
		UE_LOG(LogTemp, Warning, TEXT("Background texture"));
	}

	FSlateBrush* imageBrush = new FSlateBrush();
	imageBrush->SetResourceObject(backgroundTexture);
	imageBrush->ImageSize.X = backgroundTexture->GetSurfaceWidth();
	imageBrush->ImageSize.Y = backgroundTexture->GetSurfaceHeight();
	imageBrush->DrawAs = ESlateBrushDrawType::Box;

	return imageBrush;
}

