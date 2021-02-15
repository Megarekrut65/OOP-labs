#include "file_opening_mode.h"

namespace fmode
{
	FileMode::FileMode(const std::string& path,
		omode::Mode mode = omode::Mode::TEXT) :path(path), mode(mode)
	{
		if (mode == omode::Mode::TEXT)
		{
			in_mode = std::ios_base::in;
			out_mode = std::ios_base::out;
		}
		else if (mode == omode::Mode::BINARY)
		{
			in_mode = std::ios_base::binary;
			out_mode = std::ios_base::binary;
		}
        ffs::check_for_file(path, in_mode, out_mode);
	}
    std::vector <mon::Monster*> FileMode::find_types_time(
        mon::AttackTypes type, const std::vector<int>& find_time)
    {       
        std::vector <mon::Monster*> arr;
        std::ifstream file(path, in_mode);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file, mode);
            if (file.eof()) break;
            check_types_time(type, find_time, monster, arr);
        }
        file.close();
        return arr;
    }
    std::vector <mon::Monster*> FileMode::find_hp_damage(unsigned min_hp, unsigned max_damage)
    {
        std::vector <mon::Monster*> arr;
        std::ifstream file(path, in_mode);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file, mode);
            if (file.eof()) break;
            check_hp_damage(min_hp, max_damage, monster, arr);
        }
        file.close();
        return arr;
    }
    std::vector <mon::Monster*> FileMode::find_name(std::string fragment_name)
    {
        std::vector <mon::Monster*> arr;
        std::ifstream file(path, in_mode);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file, mode);
            if (file.eof()) break;
            check_name(fragment_name, monster, arr);
        }
        file.close();
        return arr;
    }
    unsigned FileMode::get_id()
    {
        unsigned id = 1000;
        std::ifstream file(path, in_mode);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file, mode);
            id = monster.get_id();
        }
        file.close();

        return id;
    }
    mon::Monster* FileMode::find_monster(unsigned id)
    {
        std::ifstream file(path, in_mode);
        mon::Monster* monster = nullptr;
        while (!file.eof())
        {
            monster = new mon::Monster(file, mode);
            if (file.eof()) break;
            if (id == monster->get_id()) break;
        }
        file.close();
        return monster;
    }
    void FileMode::save_edited_monster(mon::Monster monster)
    {
        std::ifstream old_file(path, in_mode);
        std::string new_path = "new_" + path;
        std::ofstream new_file(new_path, out_mode);
        bool monster_found = false;
        while (!old_file.eof())
        {
            mon::Monster read_monster = mon::Monster(old_file, mode);
            if (old_file.eof()) break;
            if (monster.get_id() == read_monster.get_id()) monster.add_to_file(new_file, mode);
            else read_monster.add_to_file(new_file, mode);
        }
        old_file.close();
        new_file.close();
        ffs::file_rename_delete(new_path, path);
    }
    void FileMode::delete_the_monster(mon::Monster monster)
    {
        std::ifstream old_file(path, in_mode);
        std::string new_path = "new_" + path;
        std::ofstream new_file(new_path, out_mode);
        bool monster_found = false;
        while (!old_file.eof())
        {
            mon::Monster read_monster = mon::Monster(old_file, mode);
            if (old_file.eof()) break;
            if (monster.get_id() != read_monster.get_id())
                read_monster.add_to_file(new_file, mode);
        }
        old_file.close();
        new_file.close();
        ffs::file_rename_delete(new_path, path);
    }
    void FileMode::append_monster(mon::Monster monster)
    {
        std::ofstream file(path, out_mode| std::ios_base::app);
        monster.add_to_file(file, mode);
        file.close();
    }
    void FileMode::write_all_monsters()
    {
        std::ifstream file(path, in_mode);
        std::size_t index = 1;
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file, mode);
            if (file.eof()) break;
            std::cout << "\n<" << index << ">" << std::endl;
            std::cout << monster << std::endl;
        }
        file.close();
    }
}