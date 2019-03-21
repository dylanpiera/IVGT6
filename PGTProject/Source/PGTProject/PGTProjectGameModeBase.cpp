#include "PGTProjectGameModeBase.h"
#include "GameHUD.h"
#include "MouseController.h"

APGTProjectGameModeBase::APGTProjectGameModeBase() : Super()
{
	//Setting HUD and Mouse to be standard HUD/Mouse
	HUDClass = AGameHUD::StaticClass();
	PlayerControllerClass = AMouseController::StaticClass();
}
