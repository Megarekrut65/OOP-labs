#pragma once
#include <vector>
#include "opening_mode.h"

namespace mmode//memory mode
{
	class MemoryMode: public om::OpeningMode
	{
	private:
		std::vector<mon::Monster> monsters;
		std::vector <std::shared_ptr<mon::Monster>> find_types_time(
			mon::AttackTypes type, const std::vector<int>& find_time);
		std::vector<std::shared_ptr<mon::Monster>> find_hp_damage(unsigned min_hp, unsigned max_damage);
		std::vector<std::shared_ptr<mon::Monster>> find_name(std::string fragment_name);
		unsigned get_id();
		std::shared_ptr<mon::Monster> find_monster(unsigned id);
		void save_edited_monster(mon::Monster monster);
		void delete_the_monster(mon::Monster monster);
		void append_monster(mon::Monster monster);
	public:
		void write_all_monsters();
	};
}