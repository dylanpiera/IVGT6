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

	/**
	 * @brief Construct a new slate begin args object
	 * 
	 */
	SLATE_BEGIN_ARGS(ToolbarGraphics) {}

	/**
	 * @brief Add new argument called OwnerHUDArg
	 * 
	 */
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	/**
	 * @brief Add new argument called DataHolderArgs
	 * 
	 */
	SLATE_ARGUMENT(TWeakObjectPtr<class ADataHolder>, DataHolderArgs);

	/**
	 * @brief 
	 * 
	 */
	SLATE_END_ARGS()

	/**
	 * @brief Constructs this widget with InArgs
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
	 * @brief Safe pointer to parent HUD
	 * 
	 */
	TWeakObjectPtr<class ADataHolder> _dataHolder;

	/* "mutable" variables are so they be updated inside "const" functions */
	/**
	 * @brief Holds current toolbar section. "mutable" variable so they be updated inside "const" functions.
	 * 
	 */
	mutable ToolbarSections CurrentSection; // 

	/**
	 * @brief Informs whether or not the view options panel should be opened. "mutable" variable so they be updated inside "const" functions.
	 * 
	 */
	mutable bool IsOpenToolbarViewPanel;

	/**
	 * @brief Sections Names. "mutable" variable so they be updated inside "const" functions.
	 * 
	 */
	mutable map<ToolbarSections, FString> SectionsTitles = {
		{RoadsSection, "Roads" },
		{BuildingsSection, "Buildings" }
	};

	/**
	 * @brief Sections Options Names. 
	 * 
	 */
	mutable map<OptionSections, FString> OptionsTitles = { 
		{ RoughRoad, "Rough Road" },
		{ EnergyBuilding, "Power Plancat"},
		{ MineralsBuilding, "Minerawr Extractor"},
		{ MoneyBuilding, "Intergalatic House"},
		{ FoodBuilding, "Cake is a Lie"}
	};

	FSlateFontInfo ArialFont;

	/**
	 * @brief Style Components. "mutable" variable so they be updated inside "const" functions.
	 * 
	 */
	enum ImageTypes { BackgroundImagePath, Road_IconPath, Building_IconPath, Road1_IconPath, Building1_IconPath,
		Building2_IconPath, Building3_IconPath, Building4_IconPath, Destroy_IconPath
	};
	map<ImageTypes, FString> ImagePaths;

	
	/**
	 * @brief Get the Section Title object name to be displayed on interface
	 * 
	 * @param Index 
	 * @return FText 
	 */
	FText GetSectionTitle(ToolbarSections Index) const;

	/**
	 * @brief Get the Option Title object
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
	 * @brief Get the Section Visibility object. Update which section should be visible
	 * 
	 * @param Index 
	 * @return EVisibility 
	 */
	EVisibility GetSectionVisibility(ToolbarSections Index) const;

	/**
	 * @brief Get the Toolbar View Visibility object
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

	/**
	 * @brief 
	 * 
	 */
	void StyleSettings();

	/**
	 * @brief Destroy building/road
	 * 
	 * @return FReply 
	 */
	FReply Destroy() const;
};

