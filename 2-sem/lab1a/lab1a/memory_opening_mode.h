#pragma once
#include <vector>
#include "opening_mode.h"

namespace mmode//memory mode
{
	class MemoryMode: public om::OpeningMode
	{
	private:
		std::vector<mon::Monster> monsters;
		std::vector <mon::Monster*> find_types_time(
			mon::AttackTypes type, const std::vector<int>& find_time);
		std::vector<mon::Monster*> find_hp_damage(unsigned min_hp,
			unsigned max_damage);
		std::vector<mon::Monster*> find_name(std::string fragment_name);
	public:
	};
}