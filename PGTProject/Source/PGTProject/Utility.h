#pragma once
/**
 * @brief 
 * 
 */
class Utility
{
public:
	template<typename compare, typename baseclass>
	/**
	 * @brief 
	 * 
	 * @param a 
	 * @param b 
	 * @return true 
	 * @return false 
	 */
	static bool compare_ptrs(baseclass* a, baseclass* b) {
		if (dynamic_cast<compare*>(a) != nullptr && dynamic_cast<compare*>(b) != nullptr)
			return true;
		return false;
	}

	template<typename compare, typename baseclass>
	/**
	 * @brief 
	 * 
	 * @param a 
	 * @return true 
	 * @return false 
	 */
	static bool compare_ptrs(baseclass* a) {
		if (dynamic_cast<compare*>(a) != nullptr)
			return true;
		return false;
	}
};