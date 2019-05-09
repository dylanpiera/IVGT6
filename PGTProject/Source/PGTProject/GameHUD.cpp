#include "GameHUD.h"
#include "MainGraphics.h"
#include "Widgets/SWeakWidget.h"
#include "Engine.h"
#include "Engine/GameViewportClient.h"

void AGameHUD::BeginPlay()
{
	// Add main widget graphics to HUD
	_mainWidget = SNew(MainGraphics).OwnerHUDArg(this);
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(_mainWidget.ToSharedRef()), 0);
	_mainWidget->SetVisibility(EVisibility::Visible);

}