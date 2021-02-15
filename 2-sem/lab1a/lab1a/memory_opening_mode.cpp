#include "memory_opening_mode.h"

namespace mmode
{
    /*unsigned get_id(const std::vector<info_monster>& all_monsters)//creates a unique id
    {
        unsigned new_id = 1000;
        int size = all_monsters.size();
        if (size == 0) return new_id;
        else return all_monsters[size - 1].id + 1;
    }
    int find_id(unsigned monster_id, const vector<info_monster>& all_monsters)
    {
        int number_monster = -1;
        for (unsigned i = 0; i < all_monsters.size(); i++)
        {
            if (monster_id == all_monsters[i].id)
            {
                number_monster = i;
                break;
            }
        }
        return number_monster;
    }
    void write_all_monsters(const vector<info_monster>& all_monsters)
    {
        if (all_monsters.size() == 0)
        {
            cout << "\nNo monsters saved!" << endl;
        }
        else cout << "\nAll monsters:" << endl;
        for (unsigned i = 0; i < all_monsters.size(); i++)
        {
            cout << "\n<" << i + 1 << ">\n";
            impl::write_monster(i, all_monsters);
        }
    }
    vector <int> find_types_time(types_of_attack one_types_attack, const int* find_time, const vector<info_monster>& all_monsters)
    {
        std::vector <int> numbers_monsters;
        for (unsigned i = 0; i < all_monsters.size(); i++)
        {
            if (one_types_attack == all_monsters[i].type_of_attack)
            {
                int* monster_time = new int[6];
                monster_time[0] = all_monsters[i].time_info.tm_year + 1900;
                monster_time[1] = all_monsters[i].time_info.tm_mon + 1;
                monster_time[2] = all_monsters[i].time_info.tm_mday;
                monster_time[3] = all_monsters[i].time_info.tm_hour;
                monster_time[4] = all_monsters[i].time_info.tm_min;
                monster_time[5] = all_monsters[i].time_info.tm_sec;
                if (is_time(find_time, monster_time)) numbers_monsters.push_back(i);
                delete[]monster_time;
            }
        }

        return numbers_monsters;
    }
    vector <int> find_hp_damage(unsigned min_hp, unsigned max_damage, const vector<info_monster>& all_monsters)
    {
        std::vector <int> numbers_monsters;
        for (unsigned i = 0; i < all_monsters.size(); i++)
        {
            if ((min_hp <= all_monsters[i].hp) && (max_damage >= all_monsters[i].damage)) numbers_monsters.push_back(i);
        }
        return numbers_monsters;
    }
    vector <int> find_name(string fragment_name, const vector<info_monster>& all_monsters)
    {
        vector <int> numbers_monsters;
        int fragment_size = fragment_name.size();
        for (unsigned i = 0; i < all_monsters.size(); i++)
        {
            string name = all_monsters[i].name;
            int name_size = name.size();
            if (fragment_size <= name_size)
            {
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                transform(fragment_name.begin(), fragment_name.end(), fragment_name.begin(), ::tolower);
                for (int j = 0; (j + fragment_size) <= name_size; j++)
                {
                    if (name.substr(j, fragment_size) == fragment_name)
                    {
                        numbers_monsters.push_back(i);
                        break;
                    }
                }
            }
        }
        return numbers_monsters;
    }*/
    std::vector <mon::Monster*> MemoryMode::find_types_time(
        mon::AttackTypes type, const std::vector<int>& find_time)
    {
        std::vector <mon::Monster*> arr;
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            if (type == monsters[i].get_type())
            {
                std::vector<int> monster_time = tm_to_vector(monsters[i].get_time());
                if (is_time(find_time, monster_time)) arr.push_back(&monsters[i]);
            }
        }

        return arr;
    }
}