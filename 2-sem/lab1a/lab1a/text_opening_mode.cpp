#include "text_opening_mode.h"

namespace tmode
{
    bool create_text_file(const string& path)//the function creates a text file if it does not exist
    {
        std::ifstream file(path);
        if (!file.is_open())
        {
            file.close();
            std::ofstream file_create(path);
            file_create.close();
            return false;
        }
        file.close();

        return true;
    }
    vector <info_monster> open_text_file(const string& path)//the function copies information from a text file to an array
    {
        vector <info_monster> all_monsters;
        if (!create_text_file(path))
        {
            cout << "\nFile not found!..." << endl;
            cout << "\nNew file created!" << endl;
        }
        else
        {
            std::ifstream file(path);
            while (!file.eof())
            {
                string line;
                line_read(file, line);
                if (line.size() == 0) break;
                unsigned id;
                id = stoi(line.substr(3));
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
                all_monsters.push_back(info_monster(name, hp, damage, chance, type_of_attack, time_info, id));
            }
            file.close();
        }
        return all_monsters;
    }
    bool save_text_file(const string& path, const vector<info_monster>& all_monsters)//The function copies information from an array into a text file
    {
        std::ofstream file(path);
        if (!file.is_open()) return false;
        for (unsigned i = 0; i < all_monsters.size(); i++)
        {
            file << "id:" << all_monsters[i].id << endl;
            file << "name:" << all_monsters[i].name << endl;
            file << "hp:" << all_monsters[i].hp << endl;
            file << "damage:" << all_monsters[i].damage << endl;
            file << "chance:" << all_monsters[i].chance << endl;
            switch (all_monsters[i].type_of_attack)
            {
            case types_of_attack::INCREASE: file << "type:" << 1 << endl;
                break;
            case types_of_attack::REPEAT: file << "type:" << 2 << endl;
                break;
            case types_of_attack::CURE: file << "type:" << 3 << endl;
                break;
            case types_of_attack::PARALYZE: file << "type:" << 4 << endl;
            }
            file << all_monsters[i].time_info.tm_hour << " "
                << all_monsters[i].time_info.tm_min << " " << all_monsters[i].time_info.tm_sec << " "
                << all_monsters[i].time_info.tm_mday << " " << all_monsters[i].time_info.tm_mon << " "
                << all_monsters[i].time_info.tm_year << endl;
        }
        file.close();
        return true;
    }
    bool add_in_text_file(info_monster monster, const string& path)//the function writes information to the end of a text file
    {
        std::ofstream file(path, std::ios_base::app);
        if (!file.is_open()) return false;
        file << "id:" << monster.id << endl;
        file << "name:" << monster.name << endl;
        file << "hp:" << monster.hp << endl;
        file << "damage:" << monster.damage << endl;
        file << "chance:" << monster.chance << endl;
        switch (monster.type_of_attack)
        {
        case types_of_attack::INCREASE: file << "type:" << 1 << endl;
            break;
        case types_of_attack::REPEAT: file << "type:" << 2 << endl;
            break;
        case types_of_attack::CURE: file << "type:" << 3 << endl;
            break;
        case types_of_attack::PARALYZE: file << "type:" << 4 << endl;
        }
        file << monster.time_info.tm_hour << " " << monster.time_info.tm_min << " "
            << monster.time_info.tm_sec << " " << monster.time_info.tm_mday << " "
            << monster.time_info.tm_mon << " " << monster.time_info.tm_year << endl;
        file.close();
        return true;
    }
    void line_read(std::ifstream& file, string& line)
    {
        getline(file, line);
        while (line.size() == 0)
        {
            if (file.eof()) break;
            getline(file, line);
        }
    }

}