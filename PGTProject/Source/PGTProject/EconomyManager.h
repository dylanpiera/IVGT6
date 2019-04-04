#pragma once

//TODO: Discuss if this should be a uentity

namespace economy_manager
{
	class EconomyManager {
	public:
		/**
		 * \brief 
		 * Stores the resources the game requires
		 */
		struct Resources
		{
			int _energy;
			int _materials;
			int _money;

			explicit Resources(const int energy = 0, const int materials = 0, const int money = 0) : _energy(energy), _materials(materials), _money(money) { }
		};
	};
};
