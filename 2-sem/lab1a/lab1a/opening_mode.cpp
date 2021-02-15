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
        mon::AttackTypes type = mrs::read_type();
        std::cout << "\nEnter the maximum date and time the monster was created:" << std::endl;
        std::vector<std::size_t> find_time = {
            mrs::read_size_t("year", 2020),
            mrs::read_size_t("month", 1, 12),
            mrs::read_size_t("day", 1, 31),
            mrs::read_size_t("hour", 0, 23),
            mrs::read_size_t("minute", 0, 59),
            mrs::read_size_t("second", 0, 59)
        };
        write_monsters_menu(find_types_time(type, find_time));
    }
    void OpeningMode::find_hp_damage_menu()
    {
        unsigned min_hp = unsigned(
            mrs::read_size_t("the minimum number of monster health units", 
                mon::Monster::min_hp, mon::Monster::max_hp));
        unsigned max_damage = unsigned(
            mrs::read_size_t("the maximum number of monster attack units", 
                mon::Monster::min_damage, mon::Monster::max_damage));
        write_monsters_menu(find_hp_damage(min_hp, max_damage));
    }
    void OpeningMode::find_name_menu()
    {
        std::string fragment_name = mrs::read_string("the full name or snippet of name of monster");
        write_monsters_menu(find_name(fragment_name));
    }
    std::tm OpeningMode::get_time_now()
    {
        time_t seconds = time(nullptr);
        std::tm time_info;
        localtime_s(&time_info, &seconds);

        return time_info;
    }
    void OpeningMode::add_new_monster()//function to create a new monster
    {
        std::cout << "\nCreate your own monster!" << std::endl;
        mon::Monster new_monster(
            mrs::read_string("a name of monster"),
            unsigned(mrs::read_size_t("a number of monster health units",
                mon::Monster::min_hp, mon::Monster::max_hp)),
            unsigned(mrs::read_size_t("a number of monster attack units",
                mon::Monster::min_damage, mon::Monster::max_damage)),
            mrs::read_double("a chance to launch a special attack of monster",
                mon::Monster::min_chance, mon::Monster::max_chance),
            mrs::read_type(),
            get_time_now(),
            get_id());
        std::cout << "\nNew monster created!\nHis personal ID: " << new_monster.get_id() << std::endl;
        std::cout << new_monster.string_time() << std::endl;
        append_monster(new_monster);
    }
    void OpeningMode::edit_monster()
    {
        unsigned monster_id = unsigned(mrs::read_size_t("id of the monster", 1000));
        mon::Monster* monster = find_monster(monster_id);
        if (monster)
        {
            while (true)
            {
                std::cout << "\nMonster:\n" << *monster << std::endl;
                cout << "\nSelect the option you want to edit:\n"
                    << "1)Name.\n2)HP.\n3)Damage.\n4)Chance to launch a special attack.\n"
                    << "5)Type of special monster attack.\n0)Exit." << std::endl;
                switch (_getch())
                {
                case '1': monster->set_name(mrs::read_string("a new name of monster"));                
                break;
                case '2': monster->set_hp(unsigned(mrs::read_size_t(
                    "a newnumber of monster health units", mon::Monster::min_hp, mon::Monster::max_hp)));
                break;
                case '3': monster->set_damage(unsigned(mrs::read_size_t(
                    "a number of monster attack units", mon::Monster::min_damage, mon::Monster::max_damage)));
                break;
                case '4': monster->set_chance(mrs::read_double(
                    "a chance to launch a special attack of monster", mon::Monster::min_chance, mon::Monster::max_chance));
                break;
                case '5': monster->set_type(mrs::read_type());
                break;
                case '0':
                {
                    save_edited_monster(*monster);
                    return;
                }
                    break;
                default: std::cout << "\nPress the correct key!" << std::endl;
                }
                break;
            }            
        }
        else std::cout << "\nMonster not found!" << std::endl;
    }
    void OpeningMode::delete_monster()
    {
        unsigned monster_id = unsigned(mrs::read_size_t("id of the monster", 1000));
        mon::Monster* monster = find_monster(monster_id);
        if (monster)    
        {
            delete_the_monster(*monster);
            std::cout << "\nThe monster - removed!" << std::endl;
        }
        else std::cout << "\nMonster not found!" << std::endl;
    }
    bool OpeningMode::is_time(std::vector<std::size_t> find_time, std::vector<std::size_t> monster_time, std::size_t index)//recursion to check that the monster is created no later than the specified time
    {
        if (index == 6) return false;
        if (monster_time[index] > find_time[index]) return false;
        else
        {
            if (index == 5) return true;
            if (monster_time[index] < find_time[index]) return true;
            return is_time(find_time, monster_time, ++index);
        }
    }
}