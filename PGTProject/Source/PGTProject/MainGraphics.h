#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "SSlateWidget.h"
#include "ToolbarGraphics.h"
#include "ToolbarActor.h"

/**
 * @brief 
 * 
 */
class PGTPROJECT_API MainGraphics : public SCompoundWidget
{
public:
	/**
	 * @brief Construct a new slate begin args object
	 * 
	 */
	SLATE_BEGIN_ARGS(MainGraphics) {}

	/**
	 * @brief Construct a new slate argument object called OwnerHUDArg
	 * 
	 */
	SLATE_ARGUMENT(TWeakObjectPtr<class AGameHUD>, OwnerHUDArg);
	/**
	 * @brief Construct a new slate argument object
	 * 
	 */
	SLATE_ARGUMENT(TWeakObjectPtr<AToolbarActor>, ToolbarActorArg);
	/**
	 * @brief Construct a new slate argument object
	 * 
	 */
	SLATE_ARGUMENT(TWeakObjectPtr<ADataHolder>, DataHolderArgs);

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

	//Safe pointer to parent HUD
	TWeakObjectPtr<class AGameHUD> _ownerHUD;
	TWeakObjectPtr<class AToolbarActor> _toolbarActor;
	TWeakObjectPtr<class ADataHolder> _dataHolder;

	TSharedPtr<ToolbarGraphics> _ownerToolbar;
	TSharedPtr<SSlateWidget> _ownerEconomyBar;
};
