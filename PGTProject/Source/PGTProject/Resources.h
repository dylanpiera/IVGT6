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

	explicit Resources(const int energy = 0, const int materials = 0, const int money = 0) : _energy(energy), _minerals(materials), _money(money) { _population = 0; }
};