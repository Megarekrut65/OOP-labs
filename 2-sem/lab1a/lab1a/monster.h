#pragma once
#include <string>
#include <vector>
#include <ctime>
#include <iostream>
#include "file_functions.h"
#include "file_mode.h"

/**
* \brief Namespace for class Monster and enum class AttackTypes.
* 
*/
namespace mon//mosnter
{
    /**
    * \brief Enum class to represent the attack types of a object of class mon::Monster
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
    * \brief Class to represent an abstract monster object.
    * 
    * The class object has the following 'characteristics':
    * - id - unique code
    * - name - the name of monster
    * - hp - health units, value from mon::Monster::min_hp to mon::Monster::max_hp
    * - damage - attack units, value from mon::Monster::min_damage to mon::Monster::max_damage
    * - chance - chance to launch a special attack, value from mon::Monster::min_chance to mon::Monster::max_chance
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
        * \brief Checks whether the hp value belongs to the specified interval.
        * 
        * If hp < mon::Monster::min_hp then hp = mon::Monster::min_hp.
        * 
        * If hp > mon::Monster::max_hp then hp = mon::Monster::max_hp.
        * 
        * \param hp - transmitted value
        * 
        * \returns - correct hp
        */
        unsigned correct_hp(unsigned hp);
        /**
        * \brief Checks whether the damage value belongs to the specified interval.
        *
        * If damage < mon::Monster::min_damage then damage = mon::Monster::min_damage.
        *
        * If damage > mon::Monster::max_damage then damage = mon::Monster::max_damage.
        *
        * \param damage - transmitted value
        *
        * \returns - correct damage
        */
        unsigned correct_damage(unsigned damage);
        /**
        * \brief Checks whether the chance value belongs to the specified interval.
        *
        * If chance < mon::Monster::min_chance then chance = mon::Monster::min_chance.
        *
        * If chance > mon::Monster::max_chance then chance = mon::Monster::max_chance.
        *
        * \param chance - transmitted value
        *
        * \returns - correct chance
        */
        double correct_chance(double chance);
        /**
        * \brief Creates the monster using data from text file.
        * 
        * File structure:
        * - id=<id>
        * - name=<name>
        * - hp=<hp>
        * - damage=<damage>
        * - chance=<chance>
        * - type=<type>
        * - <hours> <minutes> <seconds> <days> <months> <year - 1900>
        * 
        * If in file will be errors then the data will be set by default.
        * 
        * \param in - open stream for input from file
        */
        void read_from_text_file(std::ifstream& in);
        /**
        * \brief Creates the monster using data from binary file.
        *
        * File structure:<id><name size><name><hp><damage><chance><type><time_info>.
        * 
        * If in file will be errors then the data will be set by default.
        *
        * \param in - open stream for input from file
        */
        void read_from_binary_file(std::ifstream& in);
        /**
        * \brief Add the monster to text file.
        * 
        * The existence of the file must be ensured externally.
        * 
        * \param out - open stream for output to file
        */
        void add_to_text_file(std::ofstream& out);
        /**
        * \brief Add the monster to binary file.
        * 
        * The existence of the file must be ensured externally.
        *
        * \param out - open stream for output to file
        */
        void add_to_binary_file(std::ofstream& out);        
    public:
        static const unsigned max_hp;/**<the maximum value that can take 'hp'*/
        static const unsigned min_hp;/**<the minimum value that can take 'hp'*/
        static const unsigned max_damage;/**<the maximum value that can take 'damage'*/
        static const unsigned min_damage;/**<the minimum value that can take 'damage'*/
        static const double max_chance;/**<the maximum value that can take 'chance'*/
        static const double min_chance;/**<the minimum value that can take 'chance'*/
        /**
        * \brief Parameterized and default constructor.
        * 
        * The id uniqueness must be maintained manually
        */
        Monster(
            std::string name = "monster", 
            unsigned hp = 1, 
            unsigned damage = 1, 
            double chance = 0, 
            AttackTypes type = AttackTypes::INCREASE, 
            std::tm time_info = std::tm(), 
            unsigned id = 1000);
        /**
        * \brief Constructor that retrieves data from a file.
        * 
        * If in file will be errors then the data will be set by default.
        * 
        * \param in - open stream for input from file
        * \param mode - file read mode(TEXT or BINARY)
        */
        Monster(std::ifstream& in, omode::Mode mode = omode::Mode::TEXT);
        /**
        * \returns id - id of monster
        */
        unsigned get_id();
        /**
        * \returns name - name of monster
        */
        std::string get_name();
        /**
        * \returns hp - health units of monster
        */
        unsigned get_hp();
        /**
        * \returns damage - attack units of monster
        */
        unsigned get_damage();
        /**
        * \returns chance - chance to launch the spesial attack of monster
        */
        double get_chance();
        /**
        * \returns type - type of attack of monster
        */
        AttackTypes get_type();
        /**
        * \returns time_info - time of creating of monster
        */
        std::tm get_time();
        /**
        * \param name - new name
        */
        void set_name(std::string name);
        /**
        * 
        * 'hp' can be from mon::Monster::min_hp to mon::Monster::max_hp
        * \param hp - new hp
        */
        void set_hp(unsigned hp);
        /**
        *
        * 'damage' can be from mon::Monster::min_damage to mon::Monster::max_damage
        * \param damage - new damage
        */
        void set_damage(unsigned damage);
        /**
        *
        * 'chance' can be from mon::Monster::min_chance to mon::Monster::max_chance
        * \param chance - new chance
        */
        void set_chance(double chance);
        /**
        * \param type - new type
        */
        void set_type(AttackTypes type);
        /**
        * \brief Override the output operator for the monster class.
        * 
        * Displays all data about the monster.
        * 
        * \param out - stream for output
        * \param monster - object that will be printed
        * \returns stream for output
        */
        friend std::ostream& operator <<(std::ostream& out, const Monster& monster);
        /**
        * 
        * \returns a textual representation of time_info(std::tm)
        */
        std::string string_time() const;
        /**
        *
        * \returns a textual representation of type(AttackTypes)
        */
        std::string string_type() const;
        /**
        * \brief Translates std::string to AttackTypes. 
        *
        * \returns type as AttackTypes
        */
        static mon::AttackTypes string_to_type(std::string line);
        /**
        * \brief Translates AttackTypes to std::string.
        *
        * \returns type as std::string 
        */
        static std::string type_to_string(mon::AttackTypes type);
        /**
        * \brief Function which on parameter 'mode' defines 
        * in what file to add a sample
        * 
        * \param out - open stream for output to file
        * \param mode - file write mode(TEXT or BINARY)
        */
        void add_to_file(std::ofstream& out, omode::Mode mode);
    };
    
}