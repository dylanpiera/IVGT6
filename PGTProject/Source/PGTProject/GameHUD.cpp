#include "GameHUD.h"
#include "SSlateWidget.h"
#include "Widgets/SWeakWidget.h"
#include "Engine.h"
#include "Engine/GameViewportClient.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ToolbarActor.h"

/*
 * \brief
 * Adds SSlateWidget to HUD at start of game
 */
void AGameHUD::BeginPlay()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AToolbarActor::StaticClass(),
		FoundActors);
	TWeakObjectPtr<AToolbarActor> toolbar = Cast<AToolbarActor>(FoundActors[0]);
	toolbar->testFunc();

	//set widget's HUD to current HUD
	_uiWidget = SNew(SSlateWidget).OwnerHUDArg(this).ToolbarActorArg(toolbar);
	
	// Pass widget to viewport
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(_uiWidget.ToSharedRef()));

	// Set widget visible
	_uiWidget->SetVisibility(EVisibility::Visible);
}
