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

	// Add new argument called OwnerHUDArg
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	SLATE_END_ARGS()

	// Constructs this widget with InArgs
	void Construct(const FArguments& InArgs);
	
private:

	//Safe pointer to parent HUD
	TWeakObjectPtr<class AGameHUD> _ownerHUD;

	// Toolbar structure definitions
	enum ToolbarSections { RoadsSection, BuildingsSection };
	enum OptionSections { RoughRoad, EnergyBuilding, MineralsBuilding, MoneyBuilding };

	FSlateFontInfo ArialFont;
	mutable ToolbarSections CurrentSection; // Holds current toolbar section (Mutable to be updated inside "const" functions)
	mutable bool IsOpenToolbarViewPanel; // Informs whether or not the view options panel should be opened
	mutable map<ToolbarSections, FString> SectionsTitles = { // Sections Names
		{RoadsSection, "Roads" },
		{BuildingsSection, "Buildings" }
	};
	mutable map<OptionSections, FString> OptionsTitles = { // Sections Options Names
		{ RoughRoad, "Rough Road" },
		{ EnergyBuilding, "Power Plancat"},
		{ MineralsBuilding, "Minerawr Extractor"},
		{ MoneyBuilding, "Intergalatic Mint"}
	};
	map<ToolbarSections, vector<OptionSections>> Sections = { // Sections Structure
		{ RoadsSection, { RoughRoad } },
		{ BuildingsSection, { EnergyBuilding, MineralsBuilding, MoneyBuilding } }
	};

	// Get section title
	FText GetSectionTitle(ToolbarSections Index) const;
	// Get option title for section
	FText GetOptionTitle(OptionSections OptionIndex) const;
	// Change which section is selected
	FReply ChangeSection(ToolbarSections Index);
	// Update which section should be visible
	EVisibility GetSectionVisibility(ToolbarSections Index) const;
	// Get toolbar view options panel visibility
	EVisibility GetToolbarViewVisibility() const;
	// Select road option
	FReply SelectRoad(OptionSections Index);
	// Select building option
	FReply SelectBuilding(OptionSections Index);

};

