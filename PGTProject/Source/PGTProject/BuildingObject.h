#ifndef BuildingObject_Header
#define BuildingObject_Header
//#include "BuildingState.h"
#include "Resources.h"

class BuildingObject {
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

	virtual ~BuildingObject();

private:

	//BuildingState *_bState;
};
#endif