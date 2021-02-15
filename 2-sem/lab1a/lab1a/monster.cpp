#include "monster.h"

namespace mon
{
    const unsigned Monster::max_hp = 50000;
    const unsigned Monster::min_hp = 1;
    const unsigned  Monster::max_damage = 1000;
    const unsigned  Monster::min_damage = 1;
    const double  Monster::max_chance = 1;
    const double  Monster::min_chance = 0;
    Monster::Monster(
        std::string name, unsigned hp, 
        unsigned damage, double chance, 
        AttackTypes type, 
        std::tm time_info, unsigned id)
        : name(name), hp(correct_hp(hp)), damage(correct_damage(damage)), 
        chance(correct_chance(chance)), type(type), time_info(time_info), id(id) {}
    /*Monster::Monster(const Monster& monster):
        id(monster.id), name(monster.name),hp(monster.hp),
        damage(monster.damage), chance(monster.chance),
        type(monster.type), time_info(monster.time_info) {}*/
    unsigned Monster::correct_hp(unsigned hp)
    {
        if (hp < min_hp) return min_hp;
        if (hp > max_hp) return max_hp;
        return hp;
    }
    unsigned Monster::correct_damage(unsigned damage)
    {
        if (damage < min_damage) return min_damage;
        if (damage > max_damage) return max_damage;
        return damage;
    }
    double Monster::correct_chance(double chance)
    {
        if (chance < min_chance) return min_chance;
        if (chance > max_chance) return max_chance;
        return chance;
    }
    unsigned Monster::get_id()
    {
        return id;
    }
    std::string Monster::get_name()
    {
        return name;
    }
    unsigned Monster::get_hp()
    {
        return hp;
    }
    unsigned Monster::get_damage()
    {
        return damage;
    }
    double Monster::get_chance()
    {
        return chance;
    }
    AttackTypes Monster::get_type()
    {
        return type;
    }
    std::tm Monster::get_time()
    {
        return time_info;
    }
    void Monster::set_name(std::string name)
    {
        this->name = name;
    }
    void Monster::set_hp(unsigned hp)
    {
        this->hp = correct_hp(hp);
    }
    void Monster::set_damage(unsigned damage)
    {
        this->damage = correct_damage(damage);
    }
    void Monster::set_chance(double chance)
    {
        this->chance = correct_chance(chance);
    }
    void Monster::set_type(AttackTypes type)
    {
        type = type;
    }
    std::string Monster::string_time()
        const
    {
        char buffer[80];
        strftime(buffer, 80, "Creation time and date: %X  %d.%m.%Y", &time_info);
        return std::string(buffer);
    }
    std::string Monster::string_type()
        const
    {
        std::string line = "Type of special monster attack: ";
        switch (type)
        {
        case AttackTypes::INCREASE: line += "Increase damage.";
            break;
        case AttackTypes::REPEAT: line += "Repeat the attack.";
            break;
        case AttackTypes::CURE: line += "Cure yourself.";
            break;
        case AttackTypes::PARALYZE: line += "Paralyze the enemy.";
        }
        return line;
    }
    std::ostream& operator <<(std::ostream& out, const Monster& monster)
    {
        out << "ID: " << monster.id << ".\n"
            << "Name: " << monster.name << ".\n"
            << "HP: " << monster.hp << ".\n"
            << "Damage: " << monster.damage << ".\n"
            << "Chance to launch a special attack: " << monster.chance << "." << std::endl
            << monster.string_type() << std::endl
            << monster.string_time();
        return out;
    }
    void Monster::read_from_text_file(std::ifstream& in)
    {
        std::string line = ffs::line_read(in);
        if (line.size() >= 3 && line.substr(0, 3) == "id=") id = stoi(line.substr(3));
        line = ffs::line_read(in);
        if (in.eof()) return;
        if (line.size() >= 5 && line.substr(0, 5) == "name=") name = line.substr(5);
        line = ffs::line_read(in);
        if (in.eof()) return;
        if (line.size() >= 3 && line.substr(0, 3) == "hp=") hp = stoi(line.substr(3));
        line = ffs::line_read(in);
        if (in.eof()) return;
        if (line.size() >= 7 && line.substr(0, 7) == "damage=") damage = stoi(line.substr(7));
        line = ffs::line_read(in);
        if (in.eof()) return;
        if (line.size() >= 7 && line.substr(0, 7) == "chance=") chance = stod(line.substr(7));
        line = ffs::line_read(in);
        if (in.eof()) return;
        if (line.size() >= 5 && line.substr(0, 5) == "type=") type = string_to_type(line.substr(5));
        in >> time_info.tm_hour >> time_info.tm_min >> time_info.tm_sec
            >> time_info.tm_mday >> time_info.tm_mon >> time_info.tm_year;            
    }
    Monster::Monster(std::ifstream& in, omode::Mode mode): Monster()
    {
        if (mode == omode::Mode::TEXT) read_from_text_file(in);
        else if (mode == omode::Mode::BINARY) read_from_binary_file(in);
    }
    void Monster::add_to_text_file(std::ofstream& out)
    {
        out << "id=" << id << std::endl;
        out << "name=" << name << std::endl;
        out << "hp=" << hp << std::endl;
        out << "damage=" << damage << std::endl;
        out << "chance=" << chance << std::endl;
        out << type_to_string(type) << std::endl;
        out << time_info.tm_hour << " "
            << time_info.tm_min << " " << time_info.tm_sec << " "
            << time_info.tm_mday << " " << time_info.tm_mon << " "
            << time_info.tm_year << std::endl;
    }
    void Monster::read_from_binary_file(std::ifstream& in)
    {
        in.read((char*)&(id), sizeof(id));
        if (in.eof()) return;
        std::size_t size_name;
        in.read((char*)&size_name, sizeof(size_name));
        if (in.eof()) return;
        char* buffer_name = new char[size_name + 1];
        in.read(buffer_name, size_name);
        if (in.eof()) return;
        buffer_name[size_name] = '\0';
        name = buffer_name;
        in.read((char*)&(hp), sizeof(hp));
        if (in.eof()) return;
        in.read((char*)&(damage), sizeof(damage));
        if (in.eof()) return;
        in.read((char*)&(chance), sizeof(chance));
        if (in.eof()) return;
        in.read((char*)&(type), sizeof(type));
        if (in.eof()) return;
        in.read((char*)&(time_info), sizeof(time_info));
        delete[] buffer_name;
    }
    std::string Monster::type_to_string(mon::AttackTypes type)
    {
        std::string line = "type=";
        switch (type)
        {
        case AttackTypes::INCREASE: line += "INCREASE";
            break;
        case AttackTypes::REPEAT: line += "REPEAT";
            break;
        case AttackTypes::CURE: line += "CURE";
            break;
        case AttackTypes::PARALYZE: line += "PARALYZE";
        }

        return line;
    }
    mon::AttackTypes Monster::string_to_type(std::string line)
    {
        if (line == "REPEAT") return  mon::AttackTypes::REPEAT;
        if (line == "CURE") return  mon::AttackTypes::CURE;
        if (line == "PARALYZE") return  mon::AttackTypes::PARALYZE;
        return mon::AttackTypes::INCREASE;
    }
    void Monster::add_to_file(std::ofstream& out, omode::Mode mode)
    {
        if (mode == omode::Mode::TEXT) add_to_text_file(out);
        else if (mode == omode::Mode::BINARY) add_to_binary_file(out);
    }
    void Monster::add_to_binary_file(std::ofstream& out)
    {
        out.write((char*)&(id), sizeof(id));
        std::size_t size_name = name.size();
        out.write((char*)&size_name, sizeof(size_name));
        const char* buffer_name = name.c_str();
        out.write(buffer_name, size_name);
        out.write((char*)&(hp), sizeof(hp));
        out.write((char*)&(damage), sizeof(damage));
        out.write((char*)&(chance), sizeof(chance));
        out.write((char*)&(type), sizeof(type));
        out.write((char*)&(time_info), sizeof(time_info));
    }
}