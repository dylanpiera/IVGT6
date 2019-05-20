#pragma once
#include "Resources.h"
#include "ConstructionTimerActor.h"

class Building {
private:
	//ConstructionState _State;
public:
	AConstructionTimerActor* _constructionTimer;

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