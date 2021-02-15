#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "file_functions.h"
#include "file_mode.h"

/**
* Namespace for class Monster and enum class AttackTypes
* 
*/
namespace mon//mosnter
{
    /**
    * \brief Class to represent the attack types of a object of class Monster
    * 
    */
    enum class AttackTypes : int
    {
        INCREASE = 1,/**<Increase damage*/
        REPEAT,/**<Repeat the attack*/
        CURE,/**<Cure yourself*/
        PARALYZE/**<Paralyze the enemy*/
    };
    /**
    * \brief Class to represent an abstract monster object
    * 
    * The class object has the following 'characteristics': 
    * - id - unique code
    * - name - the name of monster
    * - hp - health units, value from 1 to 50000
    * - damage - attack units, value from 1 to 1000
    * - chance - chance to launch a special attack, value from 0.00 to 1.00
    * - type - type of special monster attack (AttackTypes)
    * - time_info - the time of creating the monster
    */
    class Monster
    {
    private:
        unsigned id;/**<unique code(uniqueness must be maintained manually)*/
        std::string name/**<the name of monster*/;
        unsigned hp;/**<health units*/
        unsigned damage;/**<attack units*/
        double chance;/**<chance to launch a special attack*/
        AttackTypes type;/**<type of special monster attack*/
        std::tm time_info;/**<the time of creating the monster*/
    
        /**
        * \brief Checks whether the hp value belongs to the specified interval
        * 
        * If hp < min_hp then hp = min_hp
        * 
        * If hp > max_hp then hp = max_hp
        * 
        * \param hp - transmitted value
        * 
        * \returns - correct hp
        */
        unsigned correct_hp(unsigned hp);
        /**
        * \brief Checks whether the damage value belongs to the specified interval
        *
        * If damage < min_damage then damage = min_damage
        *
        * If damage > max_damage then damage = max_damage
        *
        * \param damage - transmitted value
        *
        * \returns - correct damage
        */
        unsigned correct_damage(unsigned damage);
        /**
        * \brief Checks whether the chance value belongs to the specified interval
        *
        * If chance < min_chance then chance = min_chance
        *
        * If chance > max_chance then chance = max_chance
        *
        * \param chance - transmitted value
        *
        * \returns - correct chance
        */
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