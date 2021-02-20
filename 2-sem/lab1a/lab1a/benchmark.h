#pragma once
#include "memory_opening_mode.h"
#include "file_opening_mode.h"
#include <chrono>
#include <ctime>

/**
* \brief Namespace for class BenchmarkMode.
*/
namespace bm//benchmark mode
{
	/**
	* \brief The class measures the efficiency of the functions.
	* 
	* The functions of the various modes of the interactive mode
	*/
	class BenchmarkMode
	{
	private:
		std::shared_ptr<om::OpeningMode> open;/**<pointer to object of classes mmode::MemoryMode or fmode::FileMode*/
		std::string name_of_open;/**<name of open mode*/
		std::string folder_name;/**<name of folder where are all results*/
		const std::size_t number_of_functions;/**<number of functions to measuring*/
		std::vector<std::string> name_of_functions;/**<name of functions to measuring*/
		std::size_t inizial_monster_number;/**<starting number of monsters*/
		std::size_t current_monster_number;/**<current number of monsters*/
		std::size_t prev_monster_number;/**<number of monsters before current number*/
		std::size_t saved_monster_number;/**<number of monster before editing current number*/
		std::string text_path;/**<path to text file(place for monsters)*/
		std::string binary_path;/**<path to binary file(place for monsters)*/
		unsigned current_id;/**<current id of monster*/

		/**
		* \brief Adds size_of of object of class mmode::MemoryMode or size of text or binary files to file.
		* 
		* Also prints size_of to display.
		* 
		* \param path - path to result file
		*/
		void class_size_of(const std::string& path);
		/**
		* \brief Creates a monster with random parameters.
		*/
		void monster_generator();
		/**
		* \brief Adds the measurement result to a text file.
		* 
		* \param path - path to file
		* \param time - time of measurement
		*/
		void add_result_to_file(const std::string& path, float time);
		/**
		* \brief Measures the operating time of some functions.
		* 
		* \param index - index of function
		* \returns time of measurement
		*/
		float measurement(std::size_t index);
		/**
		* \brief Creates monster with random parameters.
		* 
		* \returns random monster
		*/
		mon::Monster get_random_monster();
		/**
		* \brief Calls necessary function.
		* 
		* \param index - index of function
		* \param monster - a monster that may be needed for functions
		*/
		void all_functions(std::size_t index, mon::Monster monster);
		/**
		* \brief Performs the actions required before each test.
		*/
		void before_testing();
		/**
		* \brief Performs the actions required before starting the measurement.
		*/
		void before_start();
		/**
		* \brief Sets the parameters needed to measure the memory mode.
		*/
		void set_memory_mode();
		/**
		* \brief Sets the parameters needed to measure the text file mode.
		*/
		void set_text_mode();
		/**
		* \brief Sets the parameters needed to measure the binary file mode.
		*/
		void set_binary_mode();
		/**
		* \brief Performs the actions required after each test.
		*/
		void finish();
		/**
		* \brief Sets new number of monsters.
		* 
		* \param more_than_one - measurement time information
		* \param coefficient - needed to increase the number of monster
		*/
		void new_number(bool more_than_one, std::size_t& coefficient);
		/**
		* \brief Measures the execution time of all functions of a particular mode.
		*/
		void testing();
	public:
		/**
		* \brief All values are set by default, except for the initial number of monsters.
		* 
		* \param inizial_monster_number - the number of monsters that will be added to the measurement class
		*/
		BenchmarkMode(std::size_t inizial_monster_number = 10);
		/**
		* \brief Satrts menu of benchmark mode.
		*/
		void start();
	};
}

