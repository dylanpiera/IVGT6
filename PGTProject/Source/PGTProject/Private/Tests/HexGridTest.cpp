#include "AutomationTest.h"
#include "AutomationEditorCommon.h"
#include "HexActor.h"
#include "HexGridManager.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(HexGridTest, "Tests.HexGridTest", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool HexGridTest::RunTest(const FString& Parameters)
{
	UWorld *world = FAutomationEditorCommonUtils::CreateNewMap();
	auto *hex = world->SpawnActor<AHexActor>();

	hex->hex = new AHexActor::Hex(32,32);

	if(hex->hex->q != 32 && hex->hex->r != 32) {
		UE_LOG(LogTemp, Error, TEXT("Incorrect Coordinates Detected"));
		return false;	
	}

	hex->Destroy();

	auto *hexgrid = world->SpawnActor<AHexGridManager>();
	hexgrid->GenerateGrid();
	hexgrid->LogGrid();

	auto *hex1 = hexgrid->GetHexAt(1,1);

	if(hex1->q != 1 && hex1->r != 1) {
		UE_LOG(LogTemp, Error, TEXT("Incorrect Coordinates Detected"));
		return false;	
	}

	return true;
}