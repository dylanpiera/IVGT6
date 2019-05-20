#include "Building.h"

// Constructor
Building::Building()
{
	_constructionTimer = NewObject<AConstructionTimerActor>();
	UE_LOG(LogTemp, Warning, TEXT("creating construction instance"));
	_constructionTimer->test();
	//if (ConstructionTimer->IsValidLowLevel()) {
	//	ConstructionTimer->OnConstruction.AddDynamic(this, &Building::WhenConstructionFinishes);
	//}
}

Building::~Building()
{
}

void Building::WhenConstructionFinishes()
{
	UE_LOG(LogTemp, Warning, TEXT("Construction finished!"));
}

void Building::BeginConstruction(int TimeInHours)
{
	_constructionTimer->StartConstruction(TimeInHours);
}