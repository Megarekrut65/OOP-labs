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
    std::tm OpeningMode::get_time_now()
    {
        time_t seconds = time(nullptr);
        std::tm time_info;
        localtime_s(&time_info, &seconds);

        return time_info;
    }
    bool OpeningMode::is_time(std::vector<int> find_time, 
        std::vector<int> monster_time, std::size_t index)
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
    mon::Monster OpeningMode::get_monster(unsigned id)
    {
        std::shared_ptr<mon::Monster> monster = find_monster(id);
        if (monster) return *monster;
        return mon::Monster();
    }
}
