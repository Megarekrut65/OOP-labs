#include "monster.h"

namespace im
{
    Monster::Monster(
        std::string name, unsigned hp, 
        unsigned damage, double chance, 
        AttackTypes type, 
        struct std::tm time_info, unsigned id)
        : name(name), hp(hp), damage(damage), chance(chance), type(type), time_info(time_info), id(id){}
  
}