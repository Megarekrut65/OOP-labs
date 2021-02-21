#pragma once
#include "monster.h"
#include "my_reads.h"
#include <algorithm>
#include <memory>

/**
* \brief Namespace for class OpeningMode.
*/
namespace om//opening mode
{
    /**
    * \brief Base class for classes mmode::MemoryMode and fmode::FileMode.
    * 
    * Must override all virtual functions to other classes follow.
    * 
    * Can perform the following functions: 
    * create, add, edit, delete and search for monsters (mon::Monster).
    */
    class OpeningMode
    {
    protected:      
        /**
        * \brief Finds monster by id and gives pointer to it.
        * 
        * Change a monster through a pointer is a bad idea.
        * 
        * \param id - id of searching monster
        * \returns pointer to searching monster
        */
        virtual std::shared_ptr<mon::Monster> find_monster(unsigned id) = 0;
        /**
        * \brief Check time correcting.
        * 
        * Recursion to check that the monster is created no 
        * later than the specified time.
        * 
        * \param find_time - searching time in array: 0-hour, 1-minute, 
        * 2-second, 3-day, 4-month, 5-year
        * \param monster_time - time of monster in array
        * \param index - recursive call index
        * \returns true if time is correct
        * \returns false if time isn't correct
        */
        bool is_time(std::vector<int> find_time, std::vector<int> monster_time, 
            std::size_t index = 0);
        /**
        * \brief Checks the 'time_info' and 'type' of monster.
        * 
        * If type of monster is searching type and monster is created no 
        * later than the searching time then monster will be added to arr.
        * 
        * \param type - searching type
        * \param find_time - searching time
        * \param monster - current monster
        * \param arr - array with right monsters
        */
        void check_types_time(mon::AttackTypes type, 
            const std::vector<int>& find_time, mon::Monster monster, 
            std::vector <std::shared_ptr<mon::Monster>>& arr);
        /**
        * \brief Checks the 'hp' and 'damage' of monster.
        *
        * If hp of monster is greater than min_ph and damage of monster 
        * is smaller than max_gamage then monster will be added to arr.
        *
        * \param min_hp - minimum possible hp
        * \param max_damage - maximum possible damage
        * \param monster - current monster
        * \param arr - array with right monsters
        */
        void check_hp_damage(unsigned min_hp, unsigned max_damage, 
            mon::Monster monster, std::vector <std::shared_ptr<mon::Monster>>& arr);
        /**
        * \brief Checks the 'name' of monster.
        *
        * If name of monster is equal to fragment_name or 
        * fragment_name is a part of monster name then monster will be added to arr.
        *
        * \param fragment_name - searching name or fragment name
        * \param monster - current monster
        * \param arr - array with right monsters
        */
        void check_name(std::string fragment_name,
            mon::Monster monster, std::vector <std::shared_ptr<mon::Monster>>& arr);
    public:
        /**
        * \brief Prints all monsters from array to display.
        *
        * \param arr - array with monsters
        */
        void write_monsters_menu(const std::vector<std::shared_ptr<mon::Monster>>& arr);
        /**
        * \brief Gives time now.
        *
        * \returns time of taking of function
        */
        std::tm get_time_now();
        /**
        * \brief Saves edited monster by id.
        * 
        * Before saving monster, its place will be found.
        * If the monster won't be found that it wan't be saved.
        * 
        * \param monster - monster that be saved.
        */
        virtual void save_edited_monster(mon::Monster monster) = 0;
        /**
        * \brief Deletes the monster by id.
        *
        * Before deleting monster, its place will be found.
        * If the monster won't be found that it wan't be deleted.
        *
        * \param monster - monster that be deleted.
        */
        virtual void delete_the_monster(mon::Monster monster) = 0;
        /**
        * \brief Add monster to the place of storage(memory or file or other).
        * 
        * Add monster to the end of place.
        * 
        * \param monster - monster that be added
        */
        virtual void append_monster(mon::Monster monster) = 0;
        /**
        * \brief Finds monster by type and creating time.
        * 
        * \returns monsters that have 'type' and are created no 
        * later than the 'find_time'
        */
        virtual std::vector <std::shared_ptr<mon::Monster>> find_types_time(
            mon::AttackTypes type, const std::vector<int>& find_time) = 0;
        /**
        * \brief Finds monster by hp and damage.
        *
        * \returns monsters that have greater hp than min_ph and 
        * smaller damage than max_damage
        */
        virtual std::vector<std::shared_ptr<mon::Monster>> find_hp_damage(
            unsigned min_hp, unsigned max_damage) = 0;
        /**
        * \brief Finds monster by name.
        *
        * \returns monsters that have name equal to fragment_name or 
        * fragment_name is a part of monster name
        */
        virtual std::vector<std::shared_ptr<mon::Monster>> find_name(
            std::string fragment_name) = 0;   
        /**
        * \brief Prints to display all monsters from the place of storage.
        */
        virtual void write_all_monsters() = 0;
        /**
        * \brief Interface for function mon::Monster::find_types_time.
        */
        void find_types_time_menu();
        /**
        * \brief Interface for function mon::Monster::find_hp_damage.
        */
        void find_hp_damage_menu();
        /**
        * \brief Interface for function mon::Monster::find_name.
        */
        void find_name_menu();
        /**
        * \brief Interface for adding monsters.
        * 
        * Gets monster information from the console and creates a new monster.
        */
        void add_new_monster();
        /**
        * \brief Interface for editing monsters.
        * 
        * Gets new monster information from the console and edites the monster.
        */
        void edit_monster();
        /**
        * \brief Interface for deleting monsters.
        *
        * Gets monster id and deletes the monster.
        */
        void delete_monster();
        /**
        * \brief Finds monster and givs it.
        * 
        * If monster won't be found then function returns default monster.
        * 
        * \param id - id of monster
        * \returns monster with 'id'
        */
        mon::Monster get_monster(unsigned id);
        /**
        * \brief Gives the size occupied by all monsters.
        * \returns size_of
        */
        virtual std::size_t get_size_of() = 0;
        /**
        * \brief Translates std::tm to std::vector.
        *
        * Adds hour to array[0], minute to array[1],
        * second to array[2], day to array[3],
        * month to array[4] and year to array[5].
        *
        * \param time_info - time structure
        * \returns array representation of time
        */
        static std::vector<int> tm_to_vector(std::tm time_info);
        /**
        * \brief Gives free id for new monster.
        *
        * The id is obtained from id of the last monster + 1.
        * \returns free id
        */
        virtual unsigned get_id() = 0;
    };
}