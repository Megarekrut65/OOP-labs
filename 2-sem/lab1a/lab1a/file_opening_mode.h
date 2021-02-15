#pragma once
#include "opening_mode.h"
#include "file_functions.h"
#include "file_mode.h"
namespace fmode//file mode
{

	class FileMode: public om::OpeningMode
	{
	private:
		const std::string path;
		omode::Mode mode;
		std::ios_base::_Openmode in_mode;
		std::ios_base::_Openmode out_mode;

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
		FileMode(const std::string& path, omode::Mode mode = omode::Mode::TEXT);
		void write_all_monsters();
	};
}