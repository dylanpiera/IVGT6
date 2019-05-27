#pragma once

class Utility
{
public:
	template<typename compare, typename baseclass>
	static bool compare_ptrs(baseclass* a, baseclass* b) {
		if (dynamic_cast<compare*>(a) != nullptr && dynamic_cast<compare*>(b) != nullptr)
			return true;
		return false;
	}

	template<typename compare, typename baseclass>
	static bool compare_ptrs(baseclass* a) {
		if (dynamic_cast<compare*>(a) != nullptr)
			return true;
		return false;
	}
};