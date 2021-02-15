#pragma once
#include <vector>
#include "opening_mode.h"

namespace mmode//memory mode
{
	class MemoryMode: public om::OpeningMode
	{
	private:
		std::vector<mon::Monster> monsters;
	public:
	};
}