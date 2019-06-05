// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "map"
#include <utility>
#include "Constants.h"
#include "DataHolder.h"

using namespace std;




class PGTPROJECT_API ToolbarGraphics : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(ToolbarGraphics) {}

	// Add new argument called OwnerHUDArg
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);
	SLATE_ARGUMENT(TWeakObjectPtr<class ADataHolder>, DataHolderArgs);

	SLATE_END_ARGS()

	
	// Constructs this widget with InArgs

	void Construct(const FArguments& InArgs);

	/*void SetBuilding(OptionSections option);
	OptionSections GetBuilding();*/
	
private:

	//Safe pointer to parent HUD
	TWeakObjectPtr<class AGameHUD> _ownerHUD;
	TWeakObjectPtr<class ADataHolder> _dataHolder;
	
	//OptionSections _building;
	/* "mutable" variables are so they be updated inside "const" functions */

	mutable ToolbarSections CurrentSection; // Holds current toolbar section
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

	// Style Components
	FSlateFontInfo ArialFont;
	enum ImageTypes { BackgroundImagePath, Road_IconPath, Building_IconPath, Road1_IconPath, Building1_IconPath,
		Building2_IconPath, Building3_IconPath, Destroy_IconPath
	};
	map<ImageTypes, FString> ImagePaths;

	// Get section name to be displayed on interface
	FText GetSectionTitle(ToolbarSections Index) const;
	// Get option title for section
	FText GetOptionTitle(OptionSections OptionIndex) const;
	// Change which section is selected
	FReply ChangeSection(ToolbarSections Index) const;
	// Update which section should be visible
	EVisibility GetSectionVisibility(ToolbarSections Index) const;
	// Get toolbar view options panel visibility
	EVisibility GetToolbarViewVisibility() const;
	// Select road option
	FReply SelectRoad(OptionSections Index) const;
	// Select building option
	FReply SelectBuilding(OptionSections Index);
	// Define style settings
	void StyleSettings();
	// Destroy building/road
	FReply Destroy() const;
};

