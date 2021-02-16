#include "opening_mode.h"

namespace om
{
    void OpeningMode::check_types_time(mon::AttackTypes type,
        const std::vector<int>& find_time, mon::Monster monster, 
        std::vector <std::shared_ptr<mon::Monster>>& arr)
    {
        if (type == monster.get_type())
        {
            std::vector<int> monster_time = tm_to_vector(monster.get_time());
            if (is_time(find_time, monster_time)) 
                arr.push_back(std::make_shared<mon::Monster>(monster));
        }
    }
    void OpeningMode::check_hp_damage(unsigned min_hp, unsigned max_damage,
        mon::Monster monster, std::vector <std::shared_ptr<mon::Monster>>& arr)
    {
        if ((min_hp <= monster.get_hp())
            && (max_damage >= monster.get_damage()))
            arr.push_back(std::make_shared<mon::Monster>(monster));
    }
    void OpeningMode::check_name(std::string fragment_name,
        mon::Monster monster, std::vector <std::shared_ptr<mon::Monster>>& arr)
    {
        std::string name = monster.get_name();
        if (fragment_name.size() <= name.size())
        {
            std::transform(name.begin(), name.end(), name.begin(), ::tolower);
            std::transform(fragment_name.begin(), fragment_name.end(), fragment_name.begin(), ::tolower);
            if (name.find(fragment_name) != std::string::npos) 
                arr.push_back(std::make_shared<mon::Monster>(monster));
        }
    }
    void OpeningMode::write_monsters_menu(const std::vector<std::shared_ptr<mon::Monster>>& arr)
    {
        if (arr.size() == 0) std::cout << "\nMonster(s) don't found!" << std::endl;
        else
        {
            std::cout << "\nMonster(s) found:" << std::endl;
            for (std::size_t i = 0; i < arr.size(); i++)
            {
                std::cout << "\n<" << i + 1 << ">" << std::endl;
                std::cout << *arr[i] << std::endl;
            }
        }
    }
    void OpeningMode::find_types_time_menu()
    {
        mon::AttackTypes type = mrs::read_type();
        std::cout << "\nEnter the maximum date and time the monster was created:" << std::endl;
        std::vector<int> find_time = {
            int(mrs::read_size_t("year", 2020)),
            int(mrs::read_size_t("month", 1, 12)),
            int(mrs::read_size_t("day", 1, 31)),
            int(mrs::read_size_t("hour", 0, 23)),
            int(mrs::read_size_t("minute", 0, 59)),
            int(mrs::read_size_t("second", 0, 59))
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
        std::string name = mrs::read_string("a name of monster");
        unsigned hp = unsigned(mrs::read_size_t("a number of monster health units",
            mon::Monster::min_hp, mon::Monster::max_hp));
        unsigned damage = unsigned(mrs::read_size_t("a number of monster attack units",
            mon::Monster::min_damage, mon::Monster::max_damage));
        double chance = mrs::read_double("a chance to launch a special attack of monster",
            mon::Monster::min_chance, mon::Monster::max_chance);
        mon::AttackTypes type = mrs::read_type();
        std::tm time_info = get_time_now();
        unsigned id = get_id();
        mon::Monster new_monster(name, hp, damage, chance,
            type, time_info, id);
        std::cout << "\nNew monster created!\nHis personal ID: " << new_monster.get_id() << std::endl;
        std::cout << new_monster.string_time() << std::endl;
        append_monster(new_monster);
    }
    void OpeningMode::edit_monster()
    {
        unsigned monster_id = unsigned(mrs::read_size_t("id of the monster", 1000));
        std::shared_ptr<mon::Monster> monster = find_monster(monster_id);
        if (monster)
        {
            while (true)
            {
                std::cout << "\nMonster:\n" << *monster << std::endl;
                std::cout << "\nSelect the option you want to edit:\n"
                    << "1)Name.\n2)HP.\n3)Damage.\n4)Chance to launch a special attack.\n"
                    << "5)Type of special monster attack.\n0)Save and back." << std::endl;
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
                    break;
                }
            }            
        }
        else std::cout << "\nMonster not found!" << std::endl;
    }
    void OpeningMode::delete_monster()
    {
        unsigned monster_id = unsigned(mrs::read_size_t("id of the monster", 1000));
        std::shared_ptr<mon::Monster> monster = find_monster(monster_id);
        if (monster)    
        {
            delete_the_monster(*monster);
            std::cout << "\nThe monster - removed!" << std::endl;
        }
        else std::cout << "\nMonster not found!" << std::endl;
    }
    bool OpeningMode::is_time(std::vector<int> find_time, std::vector<int> monster_time, std::size_t index)//recursion to check that the monster is created no later than the specified time
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
    std::vector<int> OpeningMode::tm_to_vector(std::tm time_info)
    {
        return { time_info.tm_year + 1900, time_info.tm_mon + 1,
                 time_info.tm_mday, time_info.tm_hour,
                 time_info.tm_min, time_info.tm_sec };
    }
}