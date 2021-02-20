#pragma once
#include "memory_opening_mode.h"
#include "file_opening_mode.h"
#include <chrono>
#include <ctime>

namespace bm//benchmark mode
{
	class BenchmarkMode
	{
	private:
		std::shared_ptr<om::OpeningMode> open;
		std::string name_of_open;
		std::string folder_name;
		const std::size_t number_of_functions;
		std::vector<std::string> name_of_functions;
		std::size_t inizial_monster_number;
		std::size_t current_monster_number;
		std::size_t prev_monster_number;
		std::size_t saved_monster_number;
		std::string text_path;
		std::string binary_path;
		unsigned current_id;

		void class_size_of(const std::string& path);
		void monster_generator();
		void add_result_to_file(const std::string& path, float time);
		float measurement(std::size_t index);
		mon::Monster get_random_monster();
		void all_functions(std::size_t index, mon::Monster monster);
		void before_testing();
		void before_start();
		void set_memory_mode();
		void set_text_mode();
		void set_binary_mode();
		void finish();
		void new_number(bool more_than_one, std::size_t& coefficient);
		void testing();
	public:
		BenchmarkMode(std::size_t inizial_monster_number = 10);
		void start();
	};
}

