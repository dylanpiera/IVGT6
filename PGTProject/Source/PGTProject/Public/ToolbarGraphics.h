#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "map"
#include <utility>
#include "Constants.h"
#include "DataHolder.h"

using namespace std;

/**
 * @class ToolbarGraphics
 * @brief Create UI for bottom toolbar.
 * 
 */
class PGTPROJECT_API ToolbarGraphics : public SCompoundWidget
{
public:

	/**
	 * @brief Define ToolbarGraphics slate component arguments
	 * Use pointers to GameHUD and DataHolder.
	 * @var OwnerHUDArg
	 * @var DataHolderArgs
	 * 
	 */
	SLATE_BEGIN_ARGS(ToolbarGraphics) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	SLATE_ARGUMENT(TWeakObjectPtr<class ADataHolder>, DataHolderArgs);

	SLATE_END_ARGS()

	/**
	 * @brief Handle received arguments and create UI structure.
	 * 
	 * @param InArgs 
	 */
	void Construct(const FArguments& InArgs);
	
private:

	/**
	 * @brief Safe pointer to parent HUD
	 * 
	 */
	TWeakObjectPtr<class AGameHUD> _ownerHUD;

	/**
	 * @brief Safe pointer to DataHolder class
	 * 
	 */
	TWeakObjectPtr<class ADataHolder> _dataHolder;

	/* "mutable" variables are so they be updated inside "const" functions */
	/**
	 * @brief Holds current toolbar section.
	 * Observation: This variable is declared "mutable" to allow it to be updated inside "const" functions.
	 * 
	 */
	mutable ToolbarSections CurrentSection;

	/**
	 * @brief Informs whether or not the View Options Panel should be opened.
	 * Observation: This variable is declared "mutable" to allow it to be updated inside "const" functions.
	 */
	mutable bool IsOpenToolbarViewPanel;

	/**
	 * @brief Toolbar Sections Names
	 * Observation: This variable is declared "mutable" to allow it to be updated inside "const" functions.
	 */
	mutable map<ToolbarSections, FString> SectionsTitles = {
		{RoadsSection, "Roads" },
		{BuildingsSection, "Buildings" }
	};

	/**
	 * @brief Tollbar Options Names 
	 * Observation: This variable is declared "mutable" to allow it to be updated inside "const" functions.
	 */
	mutable map<OptionSections, FString> OptionsTitles = { 
		{ RoughRoad, "Rough Road" },
		{ EnergyBuilding, "Power Plancat"},
		{ MineralsBuilding, "Minerawr Extractor"},
		{ HouseBuilding, "Intergalatic House"},
		{ FoodBuilding, "Cake is a Lie"}
	};

	FSlateFontInfo ArialFont;

	/**
	 * @brief UI Styling Components
	 * 
	 */
	enum ImageTypes { BackgroundImagePath, Road_IconPath, Building_IconPath, Road1_IconPath, Building1_IconPath,
		Building2_IconPath, Building3_IconPath, Building4_IconPath, Destroy_IconPath
	};
	map<ImageTypes, FString> ImagePaths;

	
	/**
	 * @brief Get the section name based on section index
	 * 
	 * @param Index 
	 * @return FText 
	 */
	FText GetSectionTitle(ToolbarSections Index) const;

	/**
	 * @brief Get the option name based on option index
	 * 
	 * @param OptionIndex 
	 * @return FText 
	 */
	FText GetOptionTitle(OptionSections OptionIndex) const;

	/**
	 * @brief Change which section is selected
	 * 
	 * @param Index 
	 * @return FReply 
	 */
	FReply ChangeSection(ToolbarSections Index) const;

	/**
	 * @brief Get a section visibility. Only current section should be visible if any section is opened.
	 * 
	 * @param Index 
	 * @return EVisibility 
	 */
	EVisibility GetSectionVisibility(ToolbarSections Index) const;

	/**
	 * @brief Get visibility for sections. Depends if any section is opened or not.
	 * 
	 * @return EVisibility 
	 */
	EVisibility GetToolbarViewVisibility() const;
	
	/**
	 * @brief Select road option
	 * 
	 * @param Index 
	 * @return FReply 
	 */
	FReply SelectRoad(OptionSections Index) const;

	
	/**
	 * @brief Select building option. Sets the building Index for the DataHolder.
	 * 
	 * @param Index 
	 * @return FReply 
	 */
	FReply SelectBuilding(OptionSections Index);

	FReply HoverBuilding(OptionSections Index);

	/**
	 * @brief Define UI style settings. Ex: images, icons, fonts. 
	 * 
	 */
	void StyleSettings();

	/**
	 * @brief Destroy a building or road
	 * 
	 * @return FReply 
	 */
	FReply Destroy() const;
};

