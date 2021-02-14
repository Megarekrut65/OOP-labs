#pragma once
#include "monster.h"
#include "my_reads.h"

namespace om//opening mode
{
    class OpeningMode
    {
    protected:
        const unsigned min_hp = 1;
        const unsigned min_damage = 1;
        const double min_chance = 0;
        const unsigned max_hp = 50000;
        const unsigned max_damage = 1000;
        const double max_chance = 1;

        virtual void write_monster(std::size_t index) = 0;
        virtual std::vector <std::size_t> find_types_time(
            im::AttackTypes type, const std::vector<std::size_t>& find_time) = 0;
        virtual std::vector<std::size_t> find_hp_damage(unsigned min_hp, 
            unsigned max_damage) = 0;
        virtual std::vector<std::size_t> find_name(std::string fragment_name) = 0;
        void write_time(std::tm time_info);
    public:
        void write_monsters_menu(const std::vector<std::size_t>& indexes);
        virtual void write_all_monsters() = 0;
        void find_types_time_menu();
        void find_hp_damage_menu();
        void find_name_menu();
    };
}