#ifndef Building_Header
#define Building_Header
#include "BuildingState.h"
#include "Resources.h"

class Building {
public:
	
	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingActive(Resources &resource, Resources &maintenance);

	virtual void BuildingFunction(Resources &resource);

	virtual void BuildingUpkeep(Resources &resource);

	virtual void BuildingInactive();

	virtual void BuildingConstruction(float buildTime);

	virtual void BuildingDestruction();

	//void SetState(BuildingState* state);

	virtual ~Building();

private:

	//BuildingState *_bState;
};
#endif