#pragma once
#include <iostream>
#include "memory_opening_mode.h"
#include <memory>

#include "my_reads.h"

namespace dm//demo mode
{
	class DemoMode
	{
	private:
		std::shared_ptr <om::OpeningMode> open;
		std::size_t delay;

		void demo_menu();
		void demo_read(const std::string& sentence, const std::string& value, 
			std::size_t min = std::numeric_limits<std::size_t>::min(),
			std::size_t max = std::numeric_limits<std::size_t>::max());
		void demo_read_type(mon::AttackTypes type);//1-4
		void demo_add_monster(const mon::Monster& monster);
		void demo_show_all_monsters();
		void demo_find_monsters();
		void demo_find_name();
		void demo_find_hp_damage();
		void demo_edit_monsters_menu(const mon::Monster& monster);
		void demo_edit_monster();
		void demo_delete_monster();
		void demo_exit();	
	public:
		DemoMode(std::shared_ptr <om::OpeningMode> open = nullptr, std::size_t delay = 1200);
		void start();
	};
}