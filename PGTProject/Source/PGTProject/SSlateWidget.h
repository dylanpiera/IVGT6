#pragma once
#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "GameHUD.h"
#include "ToolbarActor.h"

/**
 * @brief Makes top UI bar
 * 
 */
class PGTPROJECT_API SSlateWidget : public SCompoundWidget
{
public:
	/**
	 * @brief Construct a new slate begin args object
	 * 
	 */
	SLATE_BEGIN_ARGS(SSlateWidget)
	{}

	/**
	 * @brief Construct a new slate argument object called OwnerHUDArg
	 * 
	 */
	SLATE_ARGUMENT(TWeakObjectPtr<AGameHUD>, OwnerHUDArg);
	/**
	 * @brief Construct a new slate argument object
	 * 
	 */
	SLATE_ARGUMENT(TWeakObjectPtr<AToolbarActor>, ToolbarActorArg)
	/**
	 * @brief Ends args object
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

	TSharedPtr<STextBlock> _energyValue;
	TSharedPtr<STextBlock> _materialsValue;
	TSharedPtr<STextBlock> _moneyValue;
	TSharedPtr<STextBlock> _populationValue;
	TSharedPtr<STextBlock> _foodValue;
};
