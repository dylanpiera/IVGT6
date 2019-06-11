#pragma once
/**
 * @brief Class for reflection Functions.
 * 
 */
class Utility
{
public:
	template<typename compare, typename baseclass>
	/**
	 * @brief Compare subclasses of the base class. If subclasses are of
	 * the same type it returns true. if not they return false.
	 * 
	 * If subclass is being casted to other type of subclass it returns a nullptr.'
	 * If subclass is casted to same type subclass it returns somevalue.
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
	 * @brief Compare subclasses of the base class. If subclasses are of
	 * the same type it returns true. if not they return false.
	 * 
	 * If subclass is being casted to other type of subclass it returns a nullptr.'
	 * If subclass is casted to same type subclass it returns somevalue.
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