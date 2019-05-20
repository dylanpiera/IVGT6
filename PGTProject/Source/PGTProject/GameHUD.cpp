#include "GameHUD.h"
#include "MainGraphics.h"
#include "Widgets/SWeakWidget.h"
#include "Engine.h"
#include "Engine/GameViewportClient.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "ToolbarActor.h"

void AGameHUD::BeginPlay()
{

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),
		AToolbarActor::StaticClass(),
		FoundActors);
	TWeakObjectPtr<AToolbarActor> toolbar = Cast<AToolbarActor>(FoundActors[0]);
	toolbar->testFunc();

	_mainWidget = SNew(MainGraphics).OwnerHUDArg(this).ToolbarActorArg(toolbar);
	GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(_mainWidget.ToSharedRef()), 0);
	_mainWidget->SetVisibility(EVisibility::Visible);

}