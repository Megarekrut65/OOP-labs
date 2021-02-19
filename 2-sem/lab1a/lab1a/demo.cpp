#include "demo.h"
#include <Windows.h>

namespace dm
{
   DemoMode::DemoMode(std::shared_ptr <om::OpeningMode> open, std::size_t delay)
       :open(open),delay(delay){}
   void DemoMode::start()
   {
       if (!open) return;
       std::cout << "\nThe start of the demo mode(press <Ctrl + C> to exit)" << std::endl;
       unsigned id = 1000;
       mon::Monster monster1{ "Name1", 45602, 123, 0.12, mon::AttackTypes::CURE, open->get_time_now(), id++ },
           monster2{ "Name2", 6534, 22, 0.67, mon::AttackTypes::INCREASE, open->get_time_now(), id++ },
           monster3{ "Name3", 23556, 761, 0.99, mon::AttackTypes::REPEAT, open->get_time_now(), id++ };
       demo_menu();
       demo_add_monster(monster1);
       demo_add_monster(monster2);
       demo_add_monster(monster3);
       demo_show_all_monsters();
       demo_find_name();
       demo_find_hp_damage();
       demo_edit_monster();
       demo_delete_monster();
       demo_exit();
       std::cout << "\nThe end of the demo mode" << std::endl;
       Sleep(delay);
   }
   void DemoMode::demo_menu()
   {
       std::cout << "\nSelect the application mode:\n"
           <<"1)Interactive dialog mode. <- press\n"
           << "2)Demo mode.\n3)Automatic benchmark mode.\n0)Exit.\n";
       Sleep(delay);
       std::cout << "\nSelect the opening mode:\n1)Text mode. <- press\n"
           <<"2)Binary mode." << std::endl;
       Sleep(delay);
   }
   void DemoMode::demo_read(const std::string& sentence, const std::string& value,
       std::size_t min, std::size_t max)
   {
       mrs::same_part(sentence + mrs::min_max_part(min,max)
           +" <- write and press <Enter>\n");
       Sleep(delay);
       mrs::same_part(sentence + mrs::min_max_part(min, max)
           + value);
       Sleep(delay);
   }
   void DemoMode::demo_read_type(mon::AttackTypes type)
   {
       std::size_t index = 1;
       switch (type)
       {
       case mon::AttackTypes::INCREASE: index = 1;
           break;
       case mon::AttackTypes::REPEAT: index = 2;
           break;
       case mon::AttackTypes::CURE: index = 3;
           break;
       case mon::AttackTypes::PARALYZE: index = 4;
           break;
       default:
           break;
       }
       std::cout << "\nChoose one of the possible types of special monster attack:";
       std::string types[] = { "\n1)Increase damage.",
       "2)Repeat the attack.", "3)Cure yourself.", "4)Paralyze the enemy." };
       std::string press = " <- press";
       types[index - 1] += press;
       for (std::size_t i = 0; i < 4; i++)
       {
           std::cout << types[i] << std::endl;
       }
       Sleep(delay + 1000);
   }
   void DemoMode::demo_add_monster(const mon::Monster& monster)
   {
       std::cout << "\nMenu:\n1)Add a new monster. <- press\n"
           << "2)Show all the monsters.\n3)Find an existing monster.\n"
           << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << std::endl;
       Sleep(delay);
       std::cout << "\nCreate your own monster!" << std::endl;
       demo_read("a name of monster", monster.get_name());
       demo_read("a helth units of monster", std::to_string(monster.get_hp()),
           mon::Monster::min_hp, mon::Monster::max_hp);
       demo_read("a attack units of monster", std::to_string(monster.get_damage()),
           mon::Monster::min_damage, mon::Monster::max_damage);
       demo_read("a attack units of monster", std::to_string(monster.get_chance()),
           mon::Monster::min_chance, mon::Monster::max_chance);
       demo_read_type(monster.get_type());
       open->append_monster(monster);
       std::cout << "\nNew monster created!\nHis personal ID: " << monster.get_id() << std::endl;
       std::cout << monster.string_time() << std::endl;
       Sleep(delay);
   }
   void DemoMode::demo_show_all_monsters()
   {
       std::cout << "\nMenu:\n1)Add a new monster.\n"
           <<"2)Show all the monsters. <- press\n3)Find an existing monster.\n"
           << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << std::endl;
       Sleep(delay + 1500);
       open->write_all_monsters();
       Sleep(delay + 1500);
   }
   void DemoMode::demo_find_monsters()
   {
       std::cout << "\nMenu:\n1)Add a new monster.\n"
           <<"2)Show all the monsters.\n3)Find an existing monster. <- press\n"
           << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << std::endl;
       Sleep(delay);
   }
   void DemoMode::demo_find_name()
   {
       demo_find_monsters();
       std::cout << "\nSelect Monster Search Mode:\n"
           <<"1)Search by Name. <- press\n2)Search by hp and damage.\n"
           << "3)Search by type of special monster attack and date." << std::endl;
       Sleep(delay);
       demo_read("the full name or snippet of monster", "Me2");
       open->write_monsters_menu(open->find_name("Me1"));
       Sleep(delay + 1000);
   }
   void DemoMode::demo_find_hp_damage()
   {
       demo_find_monsters();
       std::cout << "\nSelect Monster Search Mode:\n"
           <<"1)Search by Name.\n2)Search by hp and damage. <- press\n"
           << "3)Search by type of special monster attack and date." << std::endl;
       Sleep(delay);
       unsigned min_hp = 100;
       unsigned max_damage = 500;
       demo_read("the minimum helth units of monster", std::to_string(min_hp),
           mon::Monster::min_hp, mon::Monster::max_hp);
       demo_read("the maximum attack units of monster", std::to_string(max_damage),
           mon::Monster::min_damage, mon::Monster::max_damage);
       open->write_monsters_menu(open->find_hp_damage(min_hp, max_damage));
       Sleep(delay + 1000);
   }
   void DemoMode::demo_edit_monsters_menu(const mon::Monster& monster)
   {
       Sleep(delay);
       std::cout << "\nMonster:\n" << std::endl;
       std::cout << monster << std::endl;
       Sleep(delay);
   }
   /*       
   
    void demo_edit_monster(int& delay, vector<info_monster>& demo_monsters)
    {
        cout << "\nMenu:\n1)Add a new monster.\n2)Show all the monsters.\n3)Find an existing monster.\n"
            << "4)Edit a monster. <- press\n5)Delete a monster.\n0)Back." << endl;
        Sleep(delay);
        demo_read_id(delay, demo_monsters);
        demo_edit_monsters_menu(delay, demo_monsters);
        cout << "\nSelect the option you want to edit:\n"
            << "1)Name. <- press\n2)HP.\n3)Damage.\n4)Chance to launch a special attack.\n"
            << "5)Type of special monster attack.\n0)Exit." << endl;
        Sleep(delay);
        demo_read_name(delay, "a new", "Name2");
        demo_monsters[0].name = "Name2";
        demo_edit_monsters_menu(delay, demo_monsters);
        cout << "\nSelect the option you want to edit:\n"
            << "1)Name.\n2)HP. <- press\n3)Damage.\n4)Chance to launch a special attack.\n"
            << "5)Type of special monster attack.\n0)Exit." << endl;
        Sleep(delay);
        demo_read_hp(delay, "a new", 10700);
        demo_monsters[0].hp = 10700;
        demo_edit_monsters_menu(delay, demo_monsters);
        cout << "\nSelect the option you want to edit:\n"
            << "1)Name.\n2)HP.\n3)Damage. <- press\n4)Chance to launch a special attack.\n"
            << "5)Type of special monster attack.\n0)Exit." << endl;
        Sleep(delay);
        demo_read_damage(delay, "a new", 800);
        demo_monsters[0].damage = 800;
        demo_edit_monsters_menu(delay, demo_monsters);
        cout << "\nSelect the option you want to edit:\n"
            << "1)Name.\n2)HP.\n3)Damage.\n4)Chance to launch a special attack. <- press\n"
            << "5)Type of special monster attack.\n0)Exit." << endl;
        Sleep(delay);
        demo_read_chance(delay, "a new", 0.64);
        demo_monsters[0].chance = 0.64;
        demo_edit_monsters_menu(delay, demo_monsters);
        cout << "\nSelect the option you want to edit:\n"
            << "1)Name.\n2)HP.\n3)Damage.\n4)Chance to launch a special attack.\n"
            << "5)Type of special monster attack. <- press\n0)Exit." << endl;
        Sleep(delay);
        demo_read_type(delay, 2);
        demo_monsters[0].type_of_attack = types_of_attack::REPEAT;
        demo_edit_monsters_menu(delay, demo_monsters);
        cout << "\nSelect the option you want to edit:\n"
            << "1)Name.\n2)HP.\n3)Damage.\n4)Chance to launch a special attack.\n"
            << "5)Type of special monster attack.\n0)Exit. <- press" << endl;
        Sleep(delay);
    }
    void demo_delete_monster(int& delay, vector<info_monster>& demo_monsters)
    {
        cout << "\nMenu:\n1)Add a new monster.\n2)Show all the monsters.\n3)Find an existing monster.\n"
            << "4)Edit a monster.\n5)Delete a monster. <- press\n0)Back." << endl;
        Sleep(delay);
        demo_read_id(delay, demo_monsters);
        demo_monsters.erase(demo_monsters.begin());
        cout << "\nThe monster - removed!" << endl;
        Sleep(delay);
    }
    void demo_exit(int& delay)
    {
        cout << "\nMenu:\n1)Add a new monster.\n2)Show all the monsters.\n3)Find an existing monster.\n"
            << "4)Edit a monster.\n5)Delete a monster.\n0)Back. <- press" << endl;
        Sleep(delay);
    }
    */
}