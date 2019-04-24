#pragma once
#include "Resources.h"

class Building {
public:
	
	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingFunction(Resources& resource) { 
		UE_LOG(LogTemp, Warning, TEXT("Building Function ran!"));
		resource._money -= 100;
	}

	virtual ~Building();
};