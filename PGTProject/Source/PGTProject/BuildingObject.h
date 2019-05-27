#ifndef BuildingObject_Header
#define BuildingObject_Header
#include "Resources.h"

class BuildingState;

class BuildingObject {
public:

	BuildingObject();

	/*
	 * override this and implement what the building needs to update
	*/
	virtual void BuildingActive(Resources &resource, Resources &maintenance);

	
	virtual void BuildingFunction(Resources &resource);

	/**
	 *
	*/
	virtual void BuildingUpkeep(Resources &resource);

	/**
	 *
	*/
	virtual void BuildingInactive();

	/**
	 *
	*/
	virtual void BuildingConstruction(float buildTime);

	/**
	 *
	*/
	virtual void BuildingDestruction();

	/**
	 *
	*/
	void SetState(BuildingState* state);

	/**
	 *
	*/
	BuildingState* GetState();

	virtual ~BuildingObject();

	

private:

	BuildingState *_bState;
};
#endif