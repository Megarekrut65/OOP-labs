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
}