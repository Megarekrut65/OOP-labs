#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "file_functions.h"
#include "file_mode.h"

namespace mon//mosnter
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
        std::tm time_info;
    
        unsigned correct_hp(unsigned hp);
        unsigned correct_damage(unsigned damage);
        double correct_chance(double chance);
        void read_from_text_file(std::ifstream& in);
        void read_from_binary_file(std::ifstream& in);
        void add_to_text_file(std::ofstream& out);
        void add_to_binary_file(std::ofstream& out);        
    public:
        static const unsigned max_hp;
        static const unsigned min_hp;
        static const unsigned max_damage;
        static const unsigned min_damage;
        static const double max_chance;
        static const double min_chance;
        Monster(
            std::string name = "monster", 
            unsigned hp = 1, 
            unsigned damage = 1, 
            double chance = 0, 
            AttackTypes type = AttackTypes::INCREASE, 
            std::tm time_info = std::tm(), 
            unsigned id = 1000);
        Monster(std::ifstream& in, omode::Mode mode = omode::Mode::TEXT);
        //Monster(const Monster& monster);
        unsigned get_id();
        std::string get_name();
        unsigned get_hp();
        unsigned get_damage();
        double get_chance();
        AttackTypes get_type();
        std::tm get_time();
        void set_name(std::string name);
        void set_hp(unsigned hp);
        void set_damage(unsigned damage);
        void set_chance(double chance);
        void set_type(AttackTypes type);
        friend std::ostream& operator <<(std::ostream& out, const Monster& monster);
        std::string string_time() const;
        std::string string_type() const;
        static mon::AttackTypes string_to_type(std::string line);
        static std::string type_to_string(mon::AttackTypes type);
        void add_to_file(std::ofstream& out, omode::Mode mode);
    };
    
}