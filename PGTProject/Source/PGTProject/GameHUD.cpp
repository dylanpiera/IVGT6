#include "GameHUD.h"
#include "SSlateWidget.h"
#include "ToolbarGraphics.h"
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
	_toolbarWidget = SNew(ToolbarGraphics).OwnerHUDArg(this);
	
	// Pass widget to viewport
	//GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(_uiWidget.ToSharedRef()), 0);
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(_toolbarWidget.ToSharedRef()), 0);

	// Set widget visible
	_uiWidget->SetVisibility(EVisibility::Visible);
}

float AGameHUD::GetScreenWidth() {
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	UE_LOG(LogTemp, Warning, TEXT("viewport size here %f  x %f"), ViewportSize.X, ViewportSize.Y);
	return ViewportSize.X;
}
