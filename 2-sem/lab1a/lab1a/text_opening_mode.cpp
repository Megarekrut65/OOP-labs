#include "text_opening_mode.h"

namespace tmode
{
    std::vector <mon::Monster*> TextMode::find_types_time(
        mon::AttackTypes type, const std::vector<int>& find_time)
    {
        if (!ffs::check_for_file(path)) return {};
        std::vector <mon::Monster*> arr;
        std::ifstream file(path);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file);
            if (file.eof()) break;
            check_types_time(type, find_time, monster, arr);
        }
        file.close();
        return arr;
    }
    std::vector <mon::Monster*> TextMode::find_hp_damage(unsigned min_hp, unsigned max_damage)
    {
        if (!ffs::check_for_file(path)) return {};
        std::vector <mon::Monster*> arr;
        std::ifstream file(path);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file);
            if (file.eof()) break;
            check_hp_damage(min_hp, max_damage, monster, arr);
        }
        file.close();
        return arr;
    }
    std::vector <mon::Monster*> TextMode::find_name(std::string fragment_name)
    {
        if (!ffs::check_for_file(path)) return {};
        std::vector <mon::Monster*> arr;
        std::ifstream file(path);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file);
            if (file.eof()) break;
            check_name(fragment_name, monster, arr);
        }
        file.close();
        return arr;
    }
    unsigned TextMode::get_id()
    {
        unsigned id = 1000;
        if (!ffs::check_for_file(path)) return id;  
        std::ifstream file(path);
        while (!file.eof())
        {
            std::string line = ffs::line_read(file);
            if (line.size() >= 3 && line.substr(0, 3) == "id=") id = stoi(line.substr(3));
        }
        file.close();

        return id;
    }
    mon::Monster* TextMode::find_monster(unsigned id)
    {
        if (!ffs::check_for_file(path)) return nullptr;
        std::ifstream file(path);
        mon::Monster monster;
        while (!file.eof())
        {
            monster = mon::Monster(file);
            if (file.eof()) break;
            if (id == monster.get_id()) break;
        }
        file.close();
        return &monster;
    }
    void TextMode::save_edited_monster(mon::Monster monster)
    {
        if (!ffs::check_for_file(path)) return;
        std::ifstream old_file(path);
        std::string new_path = "new_" + path;
        std::ofstream new_file(new_path);
        bool monster_found = false;
        while (!old_file.eof())
        {
            mon::Monster read_monster = mon::Monster(old_file);
            if (old_file.eof()) break;
            if (monster.get_id() == read_monster.get_id()) monster.add_to_text_file(new_file);
            else read_monster.add_to_text_file(new_file);
        }
        old_file.close();
        new_file.close();
        ffs::file_rename_delete(new_path, path);
    }
    void TextMode::delete_the_monster(mon::Monster monster)
    {
        if (!ffs::check_for_file(path)) return;
        std::ifstream old_file(path);
        std::string new_path = "new_" + path;
        std::ofstream new_file(new_path);
        bool monster_found = false;
        while (!old_file.eof())
        {
            mon::Monster read_monster = mon::Monster(old_file);
            if(old_file.eof()) break;
            if (monster.get_id() != read_monster.get_id()) 
                read_monster.add_to_text_file(new_file);
        }
        old_file.close();
        new_file.close();
        ffs::file_rename_delete(new_path, path);
    }
    void TextMode::append_monster(mon::Monster monster)
    {
        std::ofstream file(path, std::ios_base::app);
        monster.add_to_text_file(file);
        file.close();
    }
    void TextMode::write_all_monsters()
    {
        if (!ffs::check_for_file(path)) return;
        std::ifstream file(path);
        std::size_t index = 1;
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file);
            if (file.eof()) break;
            std::cout << "\n<" << index<< ">" << std::endl;
            std::cout << monster << std::endl;
        }
        file.close();
    }
}