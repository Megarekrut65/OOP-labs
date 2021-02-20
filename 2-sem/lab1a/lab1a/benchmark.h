#pragma once
#include "memory_opening_mode.h"
#include "file_opening_mode.h"
#include <chrono>
#include <ctime>

namespace bm//benchmark mode
{
	struct MeasurementResult
	{
		std::size_t number_of_monsters;
		float time;
		std::size_t size;
	};
	class BenchmarkMode
	{
	private:
		std::shared_ptr<om::OpeningMode> open;
		const std::size_t number_of_functions;
		std::vector<std::string> name_of_functions;
		std::size_t inizial_monster_number;
		std::size_t current_monster_number;
		std::size_t saved_monster_number;
		std::string text_path;
		std::string binary_path;
		unsigned current_id;

		void monster_generator();
		void add_result_to_file(const std::string& path, const MeasurementResult& result, bool need_size = false);
		float measurement(const std::string& result_path, std::size_t index);
		mon::Monster get_random_monster();
		void all_functions(std::size_t index, mon::Monster monster);
		void clear_result_files();
		void finish();
	public:
		BenchmarkMode();
		void start();
	};
}

