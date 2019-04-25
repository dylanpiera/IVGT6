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
	SLATE_BEGIN_ARGS(ToolbarGraphics) {}

	//Add new argument called OwnerHUDArg
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
private:

	//Safe pointer to parent HUD
	TWeakObjectPtr<class AGameHUD> _ownerHUD;

	// Toolbar Components
	FSlateFontInfo ArialFont;
	mutable int SectionIndex; // Mutable index to be updated inside "const" functions
	vector<string> SectionNames = { "Roads", "Buildings" };

	// First Section Components
	TSharedPtr<STextBlock> InfoText_1;
	TSharedPtr<SButton> _RoadsSectionButton;

	// Second Section Components
	TSharedPtr<STextBlock> InfoText_2;
	TSharedPtr<SButton> _BuildingsSectionButton;

	// Get section name based on index
	FText GetSectionName(int Index) const;
	// Change which section is selected
	FReply ChangeSection(int Index);
	// Update which section should be visible
	EVisibility GetSectionVisibility(int Index) const;	
	// Basic text function (FIXME: create content for sections, instead of just a text)
	FText GetInfoText() const;

};
