#include "memory_opening_mode.h"

namespace mmode
{
    void MemoryMode::write_all_monsters()
    {
        if (monsters.size() == 0) std::cout << "\nThere are no monsters here." << std::endl;
        else std::cout << "\nAll monsters:\n" << std::endl;
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            std::cout << "\n<" << i + 1 << ">" << std::endl;
            std::cout << monsters[i] << std::endl;
        }
    }
    void MemoryMode::delete_the_monster(mon::Monster monster)
    {
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            if (monster.get_id() == monsters[i].get_id())
            {
                monsters.erase(monsters.begin() + i);
                break;
            }
        }
    }
    void MemoryMode::save_edited_monster(mon::Monster monster)
    {
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            if (monster.get_id() == monsters[i].get_id())
            {
                monsters[i] = monster;
                break;
            }
        }
    }
    mon::Monster* MemoryMode::find_monster(unsigned id)
    {
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            if (id == monsters[i].get_id()) return &monsters[i];
        }
        return nullptr;
    }
    std::vector <mon::Monster*> MemoryMode::find_types_time(
        mon::AttackTypes type, const std::vector<int>& find_time)
    {
        std::vector <mon::Monster*> arr;
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            check_types_time(type, find_time, monsters[i], arr);
        }

        return arr;
    }
    std::vector<mon::Monster*> MemoryMode::find_hp_damage(unsigned min_hp, unsigned max_damage)
    {
        std::vector <mon::Monster*> arr;
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            check_hp_damage(min_hp, max_damage, monsters[i], arr);
        }
        return arr;
    }
    std::vector<mon::Monster*> MemoryMode::find_name(std::string fragment_name)
    {
        std::vector<mon::Monster*> arr;
        for (std::size_t i = 0; i < monsters.size(); i++)
        {
            check_name(fragment_name, monsters[i], arr);
        }
        return arr;
    }
    unsigned MemoryMode::get_id()
    {
        int size = monsters.size();
        if (size == 0) return 1000;
        else return monsters[size - 1].get_id() + 1;
    }
    void MemoryMode::append_monster(mon::Monster monster)
    {
        monsters.push_back(monster);
    }
}