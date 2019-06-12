#include "AutomationTest.h"
#include "BuildingState.h"
#include "Utility.h"
#include "ConstructionState.h"
#include "ActiveState.h"
#include "DestructionState.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(BuildingStateTest, "Tests.BuildingStateTest", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::EngineFilter)

bool BuildingStateTest::RunTest(const FString& Parameters)
{
	BuildingState* state;

	state = new ConstructionState();
	if (!Utility::compare_ptrs<ConstructionState, BuildingState>(state)) {
		UE_LOG(LogTemp, Error, TEXT("Error. It's not a Construction State"));
		return false;	
	}

	state = new ActiveState();
	if (!Utility::compare_ptrs<ActiveState, BuildingState>(state)) {
		UE_LOG(LogTemp, Error, TEXT("Error. It's not an Active State"));
		return false;	
	}

	state = new ConstructionState();
	if (Utility::compare_ptrs<DestructionState, BuildingState>(state)) {
		UE_LOG(LogTemp, Error, TEXT("Error. It's a Deconstruction State"));
		return false;	
	}

	return true;
}