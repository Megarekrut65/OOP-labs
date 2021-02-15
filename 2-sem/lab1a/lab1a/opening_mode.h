#pragma once
#include "monster.h"
#include "my_reads.h"

namespace om//opening mode
{
    class OpeningMode
    {
    protected:
        virtual void write_monster(std::size_t index) = 0;
        virtual std::vector <std::size_t> find_types_time(
            mon::AttackTypes type, const std::vector<std::size_t>& find_time) = 0;
        virtual std::vector<std::size_t> find_hp_damage(unsigned min_hp, 
            unsigned max_damage) = 0;
        virtual std::vector<std::size_t> find_name(std::string fragment_name) = 0;
        std::tm get_time_now();
        virtual unsigned get_id() = 0;
        virtual void append_monster(mon::Monster monster) = 0;
        virtual mon::Monster* find_monster(unsigned id) = 0;
        virtual void save_edited_monster(mon::Monster monster) = 0;
        virtual void delete_the_monster(mon::Monster monster) = 0;
        bool is_time(std::vector<std::size_t> find_time, std::vector<std::size_t> monster_time, std::size_t index = 0);
    public:
        void write_monsters_menu(const std::vector<std::size_t>& indexes);
        virtual void write_all_monsters() = 0;
        void find_types_time_menu();
        void find_hp_damage_menu();
        void find_name_menu();
        void add_new_monster();
        void edit_monster();
        void delete_monster();
    };
}