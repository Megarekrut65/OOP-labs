#pragma once
#include <vector>
#include "opening_mode.h"

/**
* \brief Namespace for class MemoryMode
*/
namespace mmode//memory mode
{
	/**
	* \brief The class for seving monsters in memory.
	* 
	* The monsters are saved in std::vector. All operations work using it.
	* 
	*/
	class MemoryMode: public om::OpeningMode
	{
	private:
		std::vector<mon::Monster> monsters;/**<The place to save the monsters*/
		/**
		* \brief Finds the monsters by type of attack and creating time.
		* 
		* For more information see this function in class om::OpeningMode.
		*/
		std::vector <std::shared_ptr<mon::Monster>> find_types_time(
			mon::AttackTypes type, const std::vector<int>& find_time);
		/**
		* \brief Finds the monsters by hp and damage.
		*
		* For more information see this function in class om::OpeningMode.
		*/
		std::vector<std::shared_ptr<mon::Monster>> find_hp_damage(unsigned min_hp, unsigned max_damage);
		/**
		* \brief Finds the monsters by name.
		*
		* For more information see this function in class om::OpeningMode.
		*/
		std::vector<std::shared_ptr<mon::Monster>> find_name(std::string fragment_name);
		/**
		* \brief Returns the free id of monster.
		* 
		* Takes the id of the end item from array and return its id + 1.
		* 
		* For more information see this function in class om::OpeningMode.
		*/
		unsigned get_id();
		/**
		* \brief Finds the monsters by id.
		* 
		* For more information see this function in class om::OpeningMode.
		*/
		std::shared_ptr<mon::Monster> find_monster(unsigned id);
		/**
		* \brief Saves the created monster in array.
		* 
		* Finds the monster in array by id and puts to this place a new monster.
		* 
		* For more information see this function in class om::OpeningMode.
		*/
		void save_edited_monster(mon::Monster monster);
		/**
		* \brief Removes the created monster from array.
		*
		* Finds the monster in array by id and removes it.
		*
		* For more information see this function in class om::OpeningMode.
		*/
		void delete_the_monster(mon::Monster monster);
		/**
		* \brief Adds a new monster to array.
		* 
		* For more information see this function in class om::OpeningMode.
		*/
		void append_monster(mon::Monster monster);
	public:
		/**
		* \brief Prints the monsters to display.
		*/
		void write_all_monsters();
	};
}