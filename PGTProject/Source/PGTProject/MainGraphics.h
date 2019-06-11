#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "SSlateWidget.h"
#include "ToolbarGraphics.h"
#include "ToolbarActor.h"

/**
 * @class MainGraphics
 * @brief Widget component that instanciates toolbar composing widgets.
 * Base of UI structure.
 * 
 */
class PGTPROJECT_API MainGraphics : public SCompoundWidget
{
public:
	/**
	 * @brief Define MainGraphics slate component arguments
	 * Child widgets require pointers to GameHUD, DataHolder and ToolbarActor.
	 * @var OwnerHUDArg
	 * @var ToolbarActorArg
	 * @var DataHolderArgs
	 * 
	 */
	SLATE_BEGIN_ARGS(MainGraphics) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);

	SLATE_ARGUMENT(TWeakObjectPtr<AToolbarActor>, ToolbarActorArg);

	SLATE_ARGUMENT(TWeakObjectPtr<ADataHolder>, DataHolderArgs);

	SLATE_END_ARGS()

	/**
	 * @brief Handle received arguments and create main UI structure.
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
	 * @brief Safe pointer to ToolbarActor
	 * 
	 */
	TWeakObjectPtr<class AToolbarActor> _toolbarActor;
	/**
	 * @brief Safe pointer to DataHolder
	 * 
	 */
	TWeakObjectPtr<class ADataHolder> _dataHolder;

	/**
	 * @brief Child widgets
	 * @var _ownerToolbar
	 * @var _ownerEconomyBar
	 */
	TSharedPtr<ToolbarGraphics> _ownerToolbar;
	TSharedPtr<SSlateWidget> _ownerEconomyBar;
};
