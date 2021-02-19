#pragma once
#include <iostream>
#include "memory_opening_mode.h"
#include <memory>
#include "my_reads.h"

/**
* \brief Namespace for class DemoMode.
*/
namespace dm//demo mode
{
	/**
	* \brief The class to demonstrate the work of the program.
	* 
	* All private functions are purely demonstrative. 
	* 
	*/
	class DemoMode
	{
	private:
		std::shared_ptr <om::OpeningMode> open;/**<pointer to object of class mmode::MemoryMode or class fmode::FileMode*/
		std::size_t delay;/**<delay each text output*/

		void demo_menu();
		void demo_read(const std::string& sentence, const std::string& value, 
			std::size_t min = std::numeric_limits<std::size_t>::min(),
			std::size_t max = std::numeric_limits<std::size_t>::max());
		void demo_read_chance(const std::string& sentence, double chance,
			double min = std::numeric_limits<double>::min(),
			double max = std::numeric_limits<double>::max());
		void demo_read_type(mon::AttackTypes type);//1-4
		void demo_add_monster(const mon::Monster& monster);
		void demo_show_all_monsters();
		void demo_find_monsters();
		void demo_find_name();
		void demo_find_hp_damage();
		void demo_edit_monsters_menu(unsigned id);
		void demo_edit_monster(unsigned id);
		void demo_delete_monster(unsigned id);
		void demo_exit();	
	public:
		/**
		* \brief Parametrized constructor.
		*/
		DemoMode(std::shared_ptr <om::OpeningMode> open = std::make_shared<mmode::MemoryMode>(),
			std::size_t delay = 1300);
		/**
		* \brief Starts the demo mode.
		*/
		void start();
	};
}