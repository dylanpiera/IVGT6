// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "vector"
#include "map"

using std::vector;
using std::map;

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
	enum ToolbarSections { RoadsSection, BuildingsSection };
	enum OptionSections { RoughRoad, EnergyBuilding, MineralsBuilding, MoneyBuilding };

	FSlateFontInfo ArialFont;
	mutable ToolbarSections CurrentSection; // Mutable to be updated inside "const" functions
	mutable bool IsOpenToolbarViewPanel;

	mutable map<ToolbarSections, FString> SectionsTitles = {
		{RoadsSection, "Roads" },
		{BuildingsSection, "Buildings" }
	};

	mutable map<OptionSections, FString> OptionsTitles = {
		{ RoughRoad, "Rough Road" },
		{ EnergyBuilding, "Power Plancat"},
		{ MineralsBuilding, "Minerawr Extractor"},
		{ MoneyBuilding, "Intergalatic Mint"}
	};

	map<ToolbarSections, vector<OptionSections>> Sections = {
		{ RoadsSection, { RoughRoad } },
		{ BuildingsSection, { EnergyBuilding, MineralsBuilding, MoneyBuilding } }
	};

	// First Section Components

	// Second Section Components

	// Get section title
	FText GetSectionTitle(ToolbarSections Index) const;
	// Change which section is selected
	FReply ChangeSection(ToolbarSections Index);
	// Update which section should be visible
	EVisibility GetSectionVisibility(ToolbarSections Index) const;
	// Toolbar view options panel visibility
	EVisibility GetToolbarViewVisibility() const;
	// Basic text function (FIXME: create content for sections, instead of just a text)
	FText GetInfoText() const;
	// Select road based on index
	FReply SelectRoad(OptionSections Index);
	// Select building based on index
	FReply SelectBuilding(OptionSections Index);

	FText GetOptionTitle(OptionSections OptionIndex) const;
};

