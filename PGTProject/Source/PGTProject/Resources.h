#pragma once

/**
  * \brief
  * Stores the resources the game requires
  */
struct Resources
{
	int _energy;
	int _minerals;
	int _money;
	int _population;
	int _food;

	int _mine;
	int _house;
	int _farm;

	explicit Resources(const int energy = 0, const int materials = 0, const int money = 0, const int food = 0, const int mine = 0, const int house = 0, const int farm = 0) : _energy(energy), _minerals(materials), _money(money), _food(food), _mine(mine), _house(house), _farm(farm) { _population = 0; }
};