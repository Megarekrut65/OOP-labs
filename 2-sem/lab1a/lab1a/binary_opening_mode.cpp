#include "binary_opening_mode.h"

namespace bmode
{
    /*void add_monster_in_files(std::ifstream& file, unsigned id, const string& txt, const string& bin)//The function adds monsters with another id to the end of the files
    {
        string line;
        string name;
        types_of_attack type_of_attack = types_of_attack::INCREASE;
        unsigned hp, damage, type;
        double chance;
        struct std::tm time_info;
        line_read(file, line);
        name = line.substr(5);
        line_read(file, line);
        hp = stoi(line.substr(3));
        line_read(file, line);
        damage = stoi(line.substr(7));
        line_read(file, line);
        chance = stod(line.substr(7));
        line_read(file, line);
        type = stoi(line.substr(5));
        switch (type)
        {
        case 1: type_of_attack = types_of_attack::INCREASE;
            break;
        case 2: type_of_attack = types_of_attack::REPEAT;
            break;
        case 3: type_of_attack = types_of_attack::CURE;
            break;
        case 4: type_of_attack = types_of_attack::PARALYZE;
        }
        file >> time_info.tm_hour >> time_info.tm_min >> time_info.tm_sec
            >> time_info.tm_mday >> time_info.tm_mon >> time_info.tm_year;
        add_in_text_file(info_monster(name, hp, damage, chance, type_of_attack, time_info, id), txt);
        add_in_binary_file(info_monster(name, hp, damage, chance, type_of_attack, time_info, id), bin);
    }
    void save_edit_monster(const string& txt, const string& bin, info_monster monster)//the function saves the files of the editable monster
    {
        std::ifstream old_file(txt);
        bool monster_found = false;
        while (!old_file.eof())
        {
            string line;
            line_read(old_file, line);
            if (line.size() == 0) break;
            if (line.substr(0, 2) == "id")
            {
                unsigned id = stoi(line.substr(3));
                if ((!monster_found) && (id == monster.id))
                {
                    monster_found = true;
                    add_in_text_file(monster, "new_" + txt);
                    add_in_binary_file(monster, "new_" + bin);
                }
                else
                {
                    add_monster_in_files(old_file, id, "new_" + txt, "new_" + bin);
                }
            }
        }
        old_file.close();
        file_replacement(txt, "new_" + txt);
        file_replacement(bin, "new_" + bin);
    }
    void delete_monster_from_files(unsigned monster_id, const string& txt, const string& bin)//function removes monster from files
    {
        std::ifstream old_file(txt);
        std::ofstream txt_file("new_" + txt);
        txt_file.close();
        std::ofstream bin_file("new_" + bin, std::ios_base::binary);
        bin_file.close();
        bool monster_found = false, the_end = false;
        while (!old_file.eof())
        {
            string line;
            line_read(old_file, line);
            if (line.size() == 0) break;
            if (line.substr(0, 2) == "id")
            {
                unsigned id = stoi(line.substr(3));
                if ((!monster_found) && (id == monster_id))
                {
                    monster_found = true;
                    while (true)
                    {
                        line_read(old_file, line);
                        if (line.size() == 0)
                        {
                            the_end = true;
                            break;
                        }
                        if (line.substr(0, 2) == "id")
                        {
                            id = stoi(line.substr(3));
                            break;
                        }
                    }
                    if (the_end) break;
                }
                add_monster_in_files(old_file, id, "new_" + txt, "new_" + bin);
            }
        }
        old_file.close();
        file_replacement(txt, "new_" + txt);
        file_replacement(bin, "new_" + bin);
    }
    bool create_binary_file(const string& path)//the function creates a binary file if it does not exist
    {
        std::ifstream file(path, std::ios_base::binary);
        if (!file.is_open())
        {

            file.close();
            std::ofstream file_create(path, std::ios_base::binary);
            file_create.close();
            return false;
        }
        file.close();
        return true;
    }
    vector <info_monster> open_binary_file(const string& path)//the function copies information from a binary file to an array
    {
        vector <info_monster> all_monsters;
        if (!create_binary_file(path))
        {
            cout << "\nFile not found!..." << endl;
            cout << "\nNew file created!" << endl;
        }
        else
        {
            std::ifstream file(path, std::ios_base::binary);
            info_monster monster;
            while (!file.eof())
            {
                file.read((char*)&(monster.id), sizeof(monster.id));
                if (file.eof()) break;
                std::size_t size_name;
                file.read((char*)&size_name, sizeof(size_name));
                char* buffer_name = new char[size_name + 1];
                file.read(buffer_name, size_name);
                buffer_name[size_name] = '\0';
                monster.name = buffer_name;
                file.read((char*)&(monster.hp), sizeof(monster.hp));
                file.read((char*)&(monster.damage), sizeof(monster.damage));
                file.read((char*)&(monster.chance), sizeof(monster.chance));
                file.read((char*)&(monster.type_of_attack), sizeof(monster.type_of_attack));
                file.read((char*)&(monster.time_info), sizeof(monster.time_info));
                all_monsters.push_back(monster);
                delete[] buffer_name;
            }
            file.close();
        }
        return all_monsters;
    }
    bool save_binary_file(const string& path, const vector<info_monster>& all_monsters)//The function copies information from an array into a binary file
    {
        std::ofstream file(path, std::ios_base::binary);
        if (!file.is_open()) return false;
        for (unsigned i = 0; i < all_monsters.size(); i++)
        {
            file.write((char*)&(all_monsters[i].id), sizeof(all_monsters[i].id));
            std::size_t size_name = all_monsters[i].name.size();
            file.write((char*)&size_name, sizeof(size_name));
            const char* buffer_name = all_monsters[i].name.c_str();
            file.write(buffer_name, size_name);
            file.write((char*)&(all_monsters[i].hp), sizeof(all_monsters[i].hp));
            file.write((char*)&(all_monsters[i].damage), sizeof(all_monsters[i].damage));
            file.write((char*)&(all_monsters[i].chance), sizeof(all_monsters[i].chance));
            file.write((char*)&(all_monsters[i].type_of_attack), sizeof(all_monsters[i].type_of_attack));
            file.write((char*)&(all_monsters[i].time_info), sizeof(all_monsters[i].time_info));
        }
        file.close();
        return true;
    }
    bool add_in_binary_file(info_monster monster, const string& path)//the function writes information to the end of a binary file
    {
        std::ofstream file(path, std::ios_base::binary | std::ios_base::app);
        if (!file.is_open()) return false;
        file.write((char*)&(monster.id), sizeof(monster.id));
        std::size_t size_name = monster.name.size();
        file.write((char*)&size_name, sizeof(size_name));
        const char* buffer_name = monster.name.c_str();
        file.write(buffer_name, size_name);
        file.write((char*)&(monster.hp), sizeof(monster.hp));
        file.write((char*)&(monster.damage), sizeof(monster.damage));
        file.write((char*)&(monster.chance), sizeof(monster.chance));
        file.write((char*)&(monster.type_of_attack), sizeof(monster.type_of_attack));
        file.write((char*)&(monster.time_info), sizeof(monster.time_info));
        file.close();
        return true;
    }*/
    BinaryMode::BinaryMode(const std::string& path) :path(path) { ffs::check_for_file(path) }
    std::vector <mon::Monster*> BinaryMode::find_types_time(
        mon::AttackTypes type, const std::vector<int>& find_time)
    {
        if (!ffs::check_for_file(path)) return {};
        std::vector <mon::Monster*> arr;
        std::ifstream file(path, std::ios_base::binary);
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file, omode::Mode::BINARY);
            if (file.eof()) break;
            check_types_time(type, find_time, monster, arr);
        }
        file.close();
        return arr;
    }
    std::vector <mon::Monster*> BinaryMode::find_hp_damage(unsigned min_hp, unsigned max_damage)
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
    std::vector <mon::Monster*> BinaryMode::find_name(std::string fragment_name)
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
    unsigned BinaryMode::get_id()
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
    mon::Monster* BinaryMode::find_monster(unsigned id)
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
    void BinaryMode::save_edited_monster(mon::Monster monster)
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
    void BinaryMode::delete_the_monster(mon::Monster monster)
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
            if (monster.get_id() != read_monster.get_id())
                read_monster.add_to_text_file(new_file);
        }
        old_file.close();
        new_file.close();
        ffs::file_rename_delete(new_path, path);
    }
    void BinaryMode::append_monster(mon::Monster monster)
    {
        std::ofstream file(path, std::ios_base::app);
        monster.add_to_text_file(file);
        file.close();
    }
    void BinaryMode::write_all_monsters()
    {
        if (!ffs::check_for_file(path)) return;
        std::ifstream file(path);
        std::size_t index = 1;
        while (!file.eof())
        {
            mon::Monster monster = mon::Monster(file);
            if (file.eof()) break;
            std::cout << "\n<" << index << ">" << std::endl;
            std::cout << monster << std::endl;
        }
        file.close();
    }*/
}