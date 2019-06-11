#pragma once
/**
 * @brief Contains some utilities used throughout the game's code
 */
class Utility
{
public:
	template<typename compare, typename baseclass>
	/**
	 * @brief Checks if two pointers that have the same parent class are also an instance of the same child class.
	 * 
	 * @param a Pointer a
	 * @param b Pointer b
	 * @return true If a & b are both of type compare
	 * @return false If a & b are not both of type compare
	 */
	static bool compare_ptrs(baseclass* a, baseclass* b) {
		if (dynamic_cast<compare*>(a) != nullptr && dynamic_cast<compare*>(b) != nullptr)
			return true;
		return false;
	}

	template<typename compare, typename baseclass>
	/**
	 * @brief Checks if a pointer of some parent class is also of a child type.
	 * 
	 * @param a The pointer to check
	 * @return true If a is of type compare
	 * @return false If a is not of type compare
	 */
	static bool compare_ptrs(baseclass* a) {
		if (dynamic_cast<compare*>(a) != nullptr)
			return true;
		return false;
	}
};