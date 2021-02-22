#include "file_opening_mode.h"

namespace fmode
{
    std::size_t FileMode::get_size_of()
    {
        std::ifstream file(path, in_mode);
        file.seekg(0, std::ios_base::end);
        std::size_t sizef = size_t(file.tellg());
        file.close();

        return sizef;
    }
	FileMode::FileMode(const std::string& path,
		omode::Mode mode) :path(path), mode(mode), 
        in_mode(std::ios_base::in), out_mode(std::ios_base::out)
	{
        if (mode == omode::Mode::BINARY)
		{
			in_mode = std::ios_base::binary;
			out_mode = std::ios_base::binary;
		}
        ffs::check_for_file(path, in_mode, out_mode);
	}
    std::vector <std::shared_ptr<mon::Monster>> FileMode::find_types_time(
        mon::AttackTypes type, const std::vector<int>& find_time)
    {       
        std::vector <std::shared_ptr<mon::Monster>> arr;
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
    std::vector <std::shared_ptr<mon::Monster>> FileMode::find_hp_damage(unsigned min_hp, unsigned max_damage)
    {
        std::vector <std::shared_ptr<mon::Monster>> arr;
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
    std::vector <std::shared_ptr<mon::Monster>> FileMode::find_name(std::string fragment_name)
    {
        std::vector <std::shared_ptr<mon::Monster>> arr;
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
            if (file.eof()) break;
            std::cout << monster << std::endl;
            id = monster.get_id() + 1;
        }
        file.close();

        return id;
    }
    std::shared_ptr<mon::Monster> FileMode::find_monster(unsigned id)
    {
        std::ifstream file(path, in_mode);
        mon::Monster monster;
        while (!file.eof())
        {
            monster = mon::Monster(file, mode);
            if (file.eof()) break;
            if (id == monster.get_id())
            {
                return std::make_shared<mon::Monster>(monster);
                file.close();
            }
        }
        file.close();
        return nullptr;
    }
    void FileMode::save_edited_monster(mon::Monster monster)
    {
        std::ifstream old_file(path, in_mode);
        std::string new_path = "new_" + path;
        std::ofstream new_file(new_path, out_mode);
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
}
