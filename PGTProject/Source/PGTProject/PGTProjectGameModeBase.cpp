#include "PGTProjectGameModeBase.h"
#include  "GameHUD.h"

APGTProjectGameModeBase::APGTProjectGameModeBase() : Super()
{
	HUDClass = AGameHUD::StaticClass();
}
