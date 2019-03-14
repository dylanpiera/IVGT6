#include "GameHUD.h"
#include "SSlateWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine.h"
#include "Engine/GameViewportClient.h"

void AGameHUD::BeginPlay()
{
	_uiWidget = SNew(SSlateWidget).OwnerHUDArg(this);
	
	// Pass our viewport a weak ptr to our widget
	// Viewport's weak ptr will not give Viewport ownership of Widget
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(_uiWidget.ToSharedRef()));

	// Set widget's properties as visible (sets child widget's properties recursively)
	_uiWidget->SetVisibility(EVisibility::Visible);
}
