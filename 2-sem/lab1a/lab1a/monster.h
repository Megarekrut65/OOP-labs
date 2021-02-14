#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>

namespace im//info monster
{
    enum class AttackTypes : int
    {
        INCREASE = 1,
        REPEAT,
        CURE,
        PARALYZE
    };
    class Monster
    {
    private:
        unsigned id;
        std::string name;
        unsigned hp;
        unsigned damage;
        double chance;
        AttackTypes type;
        struct std::tm time_info;
       
    public:
        Monster(
            std::string name = "NONE", 
            unsigned hp = 0, 
            unsigned damage = 0, 
            double chance = 0, 
            AttackTypes type = AttackTypes::INCREASE, 
            std::tm time_info = std::tm(), 
            unsigned id = 1000);
    };
    
}