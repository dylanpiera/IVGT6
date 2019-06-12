#include "AutomationTest.h"
#include "AutomationEditorCommon.h"
#include "EconomyManager.h"
#include "GameTickManager.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(GameTickManagerTest, "Tests.GameTickManagerTest", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool GameTickManagerTest::RunTest(const FString& Parameters)
{
	UWorld *world = FAutomationEditorCommonUtils::CreateNewMap();
	auto *economyManager = world->SpawnActor<AEconomyManager>();
	auto *gameTickManager = world->SpawnActor<AGameTickManager>();

	economyManager->InitResources();
	gameTickManager->EconomyManager = economyManager;
	gameTickManager->Debug = false;
	gameTickManager->bCanTick = true;

	for(int i = 0; i < 25; i++) {
		gameTickManager->GameTick();
	}

	if(gameTickManager->currentHour != 1) {
		UE_LOG(LogTemp, Error, TEXT("Current Hour != 1"));
		return false;
	}

	return true;
}