#pragma once
#include "opening_mode.h"
#include "file_functions.h"
#include "file_mode.h"
/**
* \brief Namespace for class FileMode.
*/
namespace fmode//file mode
{
	/**
	* \brief The class for seving monsters in files(text or binary).
	* 
	* The monsters are saved in file. All operations work using it.
	* 
	* After the end of work of program, the monsters won't be deleted 
	* and than you can take it from file.
	*/
	class FileMode: public om::OpeningMode
	{
	private:
		const std::string path;/**<the path to file*/
		omode::Mode mode;/**<the open mode, see omode::Mode*/
		std::ios_base::_Openmode in_mode;/**the mode to input data*/
		std::ios_base::_Openmode out_mode;/**the mode to output data*/
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
		* Takes the id of the end item from file and return its id + 1.
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
		* \brief Saves the created monster in file.
		*
		* Consistently reads the monsters from old file. If there is the monster 
		* with required id then to new file will be added monster that be edited.
		* Else will add this monster to new file.
		*
		* For more information see this function in class om::OpeningMode.
		*/
		void save_edited_monster(mon::Monster monster);
		/**
		* \brief Removes the created monster from file.
		*
		* Consistently reads the monsters from old file. If there is the monster 
		* with required id then it won't be added to new file.
		* Else will add this monster to new file.
		* 
		* For more information see this function in class om::OpeningMode.
		*/
		void delete_the_monster(mon::Monster monster);
		/**
		* \brief Adds a new monster to file.
		*
		* For more information see this function in class om::OpeningMode.
		*/
		void append_monster(mon::Monster monster);
	public:
		/**
		* \brief Paramatrized constructor.
		* 
		* \param path - path to file
		* \param mode - opening mode(text or binary)
		*/
		FileMode(const std::string& path, omode::Mode mode = omode::Mode::TEXT);
		/**
		* \brief Gives the size occupied by all monsters.
		* \returns size_of of file with monsters
		*/
		std::size_t get_size_of();
	};
}
