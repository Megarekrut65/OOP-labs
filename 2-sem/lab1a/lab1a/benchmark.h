#pragma once
#include "memory_opening_mode.h"
#include "file_opening_mode.h"

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
		std::size_t inizial_monster_number;
		std::size_t current_monster_number;
		std::size_t saved_monster_number;
		std::string text_path;
		std::string binary_path;
		unsigned current_id;
		void monster_generator();
		std::size_t size_file(const std::string& path);
		void add_program_test(const std::string& path, const MeasurementResult& result, bool need_size = false);
		/*float measurement_open_txt();
		float measurement_open_bin();
		float measurement_save_txt();
		float measurement_save_bin();
		float measurement_name_find();
		float measurement_hp_damage_find();
		float measurement_time_type_find();
		void clear_result_files();
		void benchmark_mode();
		void file_replacement(const string&, const string&);*/
	public:
		BenchmarkMode();
		//void start();
	};
}

