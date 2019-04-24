// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "vector"
#include "string"

using std::vector;
using std::string;

class PGTPROJECT_API ToolbarGraphics : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(ToolbarGraphics)
	{
	}

	//Add new argument called OwnerHUDArg
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	SLATE_END_ARGS()

		/** Constructs this widget with InArgs */
		void Construct(const FArguments& InArgs);
	
	/** Get the visibility of the top panel depending on overlay visibility */
	EVisibility GetTopPanelVisibility() const;
	EVisibility GetSectionVisibility(int Index) const;

	/** Get the current information to show */
	FText GetInfoText() const;

//	FSlateBrush* GetImageBrush();
	FSlateBrush ItemBrush;

private:

	//Safe pointer to parent HUD
	TWeakObjectPtr<class AGameHUD> _ownerHUD;

	// Menu components
	TSharedPtr<STextBlock> InfoText;
	TSharedPtr<STextBlock> InfoText1;
	TSharedPtr<STextBlock> InfoText2;
	TSharedPtr<SHorizontalBox> ViewSection;

	//Declaring button
	TSharedPtr<SButton> _RoadsSectionButton;
	TSharedPtr<SButton> _BuildingsSectionButton;

	FText GetSectionName(int Index) const;
	FReply ChangeSection(int Index);
	const FSlateBrush* GetImageBrush() const;

	FSlateFontInfo ArialFont;
	mutable int SectionIndex; // Mutable index to be updated inside "const" functions

	vector<string> SectionNames = {"Roads", "Buildings"};
};
