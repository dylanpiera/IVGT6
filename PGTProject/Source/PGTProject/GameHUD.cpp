#include "GameHUD.h"
#include "SSlateWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine.h"
#include "Engine/GameViewportClient.h"

/*
 * \brief
 * Adds SSlateWidget to HUD at start of game
 */
void AGameHUD::BeginPlay()
{
	//set widget's HUD to current HUD
	_uiWidget = SNew(SSlateWidget).OwnerHUDArg(this);
	
	// Pass widget to viewport
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(_uiWidget.ToSharedRef()));

	// Set widget visible
	_uiWidget->SetVisibility(EVisibility::Visible);
}
