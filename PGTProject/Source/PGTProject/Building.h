#pragma once
#include "Resources.h"
//#include "ConstructionTimerActor.h"

class AConstructionTimerActor;

class Building {
private:
	//ConstructionState _State;
	AConstructionTimerActor* _constructionTimer;
	
	void GetConstructionTimer();
public:
	//AConstructionManager* _constructionManager;

	// Constructor
	Building();

	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingFunction(Resources& resource) { 
		resource._money -= 100;
	}

	virtual ~Building();

	void BeginConstruction(int TimeInHours);

	void WhenConstructionFinishes();
};