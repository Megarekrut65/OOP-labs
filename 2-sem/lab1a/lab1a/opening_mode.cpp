#include "opening_mode.h"

namespace om
{
    void OpeningMode::write_monsters_menu(const std::vector<std::size_t>& indexes)
    {
        if (indexes.size() == 0) std::cout << "\nMonster(s) don't found!" << std::endl;
        else
        {
            std::cout << "\nMonster(s) found:" << std::endl;
            std::size_t number = 0;
            for (std::size_t i = 0; i < indexes.size(); i++)
            {
                std::cout << "\n<" << ++number << ">" << std::endl;
                write_monster(indexes[i]);
            }
        }
    }
    void OpeningMode::find_types_time_menu()
    {
        im::AttackTypes type = mrs::read_type();
        std::cout << "\nEnter the maximum date and time the monster was created:" << std::endl;
        std::vector<std::size_t> find_time = {
            mrs::read_size_t("year(2020-....)", 2020),
            mrs::read_size_t("month(1-12)", 1, 12),
            mrs::read_size_t("day(1-31)", 1, 31),
            mrs::read_size_t("hour(0-23)", 0, 23),
            mrs::read_size_t("minute(0-59)", 0, 59),
            mrs::read_size_t("second(0-59)", 0, 59)
        };
        write_monsters_menu(find_types_time(type, find_time));
    }
    void OpeningMode::find_hp_damage_menu()
    {
        unsigned min_hp = unsigned(
            mrs::read_size_t("the minimum number of monster health units (1-50000)", this->min_hp,this->max_hp));
        unsigned max_damage = unsigned(mrs::read_size_t("the maximum number of monster attack units (1-1000)", this->min_damage, this->max_damage));
        write_monsters_menu(find_hp_damage(min_hp, max_damage));
    }
    void OpeningMode::find_name_menu()
    {
        std::string fragment_name = mrs::read_string("the full name or snippet of name of monster");
        write_monsters_menu(find_name(fragment_name));
    }
    void OpeningMode::write_time(std::tm time_info)
    {
        char buffer[80];
        strftime(buffer, 80, "Creation time and date: %X  %d.%m.%Y", &time_info);
        std::cout << buffer << std::endl;
    }
    void OpeningMode::add_new_monster()//function to create a new monster
    {
        std::cout << "\nCreate your own monster!" << std::endl;
        std::string name = mrs::read_string("a name of monster");
        unsigned hp = mrs::read_size_t("a number of monster health units (1-50000)", 1, 50000);
        unsigned damage = read_damage("a");
        double chance = read_chance("a");
        types_of_attack type_of_attack = read_type();
        info_monster new_monster(name, hp, damage, chance, type_of_attack, all_monsters);
        cout << "\nNew monster created!\nHis personal ID: " << new_monster.id << endl;
        write_time(new_monster.time_info);
        all_monsters.push_back(new_monster);
        if (!add_in_text_file(new_monster, "text.txt") || !add_in_binary_file(new_monster, "binary.bin"))
        {
            cout << "\nError saving file!..." << endl;
        }
    }
}