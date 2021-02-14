#include "demo.h"

namespace dm
{
    void demo_menu(int& delay)
    {
        cout << "\nSelect the application mode:\n1)Interactive dialog mode. <- press\n"
            << "2)Demo mode.\n3)Automatic benchmark mode.\n0)Exit.\n";
        Sleep(delay);
        cout << "\nSelect the opening mode:\n1)Text mode. <- press\n2)Binary mode." << endl;
        Sleep(delay);
    }
    void demo_read_name(int& delay, const string& sentence, const string& name)
    {
        cout << "\nEnter " << sentence << " name of monster: <- write "
            << sentence << " name and press <Enter>\n";
        Sleep(delay);
        cout << "Enter " << sentence << " name of monster: " << name << endl;
        Sleep(delay);
    }
    void demo_read_hp(int& delay, const string& sentence, const unsigned& hp)
    {
        cout << "\nEnter " << sentence << " number of monster health units (1-50000): <- write "
            << sentence << " hp and press <Enter>\n";
        Sleep(delay);
        cout << "Enter " << sentence << " number of monster health units (1-50000): " << hp << endl;
        Sleep(delay);
    }
    void demo_read_damage(int& delay, const string& sentence, const unsigned& damage)
    {
        cout << "\nEnter " << sentence
            << " number of monster attack units (1-1000): <- write "
            << sentence << " damage and press <Enter>\n";
        Sleep(delay);
        cout << "Enter " << sentence
            << " number of monster attack units (1-1000): " << damage << endl;
        Sleep(delay);
    }
    void demo_read_chance(int& delay, const string& sentence, const double& chance)
    {
        cout << "\nEnter " << sentence
            << " chance to launch a special attack of monster (0.00 - 1.00): <- write "
            << sentence << " chance and press <Enter>\n";
        Sleep(delay);
        cout << "Enter " << sentence
            << " chance to launch a special attack of monster (0.00 - 1.00): " << chance << endl;
        Sleep(delay);
    }
    void demo_read_type(int& delay, const short& type_of_attack)
    {
        cout << "\nChoose one of the possible types of special monster attack:";
        switch (type_of_attack)
        {
        case 1: cout << "\n1)Increase damage. <- press\n"
            << "2)Repeat the attack.\n3)Cure yourself.\n4)Paralyze the enemy." << endl;
            break;
        case 2: cout << "\n1)Increase damage.\n"
            << "2)Repeat the attack. <- press\n3)Cure yourself.\n4)Paralyze the enemy." << endl;
        }
        Sleep(delay + 1000);
    }
    void demo_add_monster(int& delay, vector <info_monster>& demo_monsters)
    {
        cout << "\nMenu:\n1)Add a new monster. <- press\n2)Show all the monsters.\n3)Find an existing monster.\n"
            << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << endl;
        Sleep(delay);
        cout << "\nCreate your own monster!" << endl;
        demo_read_name(delay, "a", "Name1");
        demo_read_hp(delay, "a", 8421);
        demo_read_damage(delay, "a", 911);
        demo_read_chance(delay, "a", 0.32);
        demo_read_type(delay, 1);
        demo_monsters.push_back(info_monster("Name1", 8421, 911, 0.32, types_of_attack::INCREASE, demo_monsters));
        cout << "\nNew monster created!\nHis personal ID: " << demo_monsters[0].id << endl;
        write_time(demo_monsters[0].time_info);
        Sleep(delay);
    }
    void demo_show_all_monsters(int& delay, const vector <info_monster>& demo_monsters)
    {
        cout << "\nMenu:\n1)Add a new monster.\n2)Show all the monsters. <- press\n3)Find an existing monster.\n"
            << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << endl;
        Sleep(delay + 1000);
        write_all_monsters(demo_monsters);
        Sleep(delay + 1000);
    }
    void demo_find_monsters(int& delay)
    {
        cout << "\nMenu:\n1)Add a new monster.\n2)Show all the monsters.\n3)Find an existing monster. <- press\n"
            << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << endl;
        Sleep(delay);
    }
    void demo_find_name(int& delay, const vector<info_monster>& demo_monsters)
    {
        demo_find_monsters(delay);
        cout << "\nSelect Monster Search Mode:\n1)Search by Name. <- press\n2)Search by hp and damage.\n"
            << "3)Search by type of special monster attack and date." << endl;
        Sleep(delay);
        demo_read_name(delay, "the full name or snippet of", "Me1");
        write_monsters_menu(find_name("Me1", demo_monsters), demo_monsters);
        Sleep(delay + 1000);
    }
    void demo_find_hp_damage(int& delay, const vector<info_monster>& demo_monsters)
    {
        demo_find_monsters(delay);
        cout << "\nSelect Monster Search Mode:\n1)Search by Name.\n2)Search by hp and damage. <- press\n"
            << "3)Search by type of special monster attack and date." << endl;
        Sleep(delay);
        unsigned min_hp = demo_monsters[0].hp - 100;
        unsigned max_damage = demo_monsters[0].damage + 20;
        demo_read_hp(delay, "the minimum", min_hp);
        demo_read_damage(delay, "the maximum", max_damage);
        write_monsters_menu(find_hp_damage(min_hp, max_damage, demo_monsters), demo_monsters);
        Sleep(delay + 1000);
    }
    void demo_find_types_time(int& delay, const vector<info_monster>& demo_monsters)
    {
        demo_find_monsters(delay);
        cout << "\nSelect Monster Search Mode:\n1)Search by Name.\n2)Search by hp and damage.\n"
            << "3)Search by type of special monster attack and date. <- press" << endl;
        Sleep(delay);
        types_of_attack type = demo_monsters[0].type_of_attack;
        demo_read_type(delay, 1);
        cout << "\nEnter the maximum date and time the monster was created:" << endl;
        int* find_time = new int[6];
        find_time[0] = demo_monsters[0].time_info.tm_year + 1901;
        find_time[1] = demo_monsters[0].time_info.tm_mon + 1;
        find_time[2] = demo_monsters[0].time_info.tm_mday;
        find_time[3] = demo_monsters[0].time_info.tm_hour;
        find_time[4] = demo_monsters[0].time_info.tm_min;
        find_time[5] = demo_monsters[0].time_info.tm_sec;
        cout << "\nEnter year(2020-....): <- write a year and press <Enter>" << endl;
        Sleep(delay);
        cout << "Enter year(2020-....): " << find_time[0] << endl;
        cout << "\nEnter month(1-12): <- write a month and press <Enter>" << endl;
        Sleep(delay);
        cout << "Enter month(1-12): " << find_time[1] << endl;
        cout << "\nEnter day(1-31): <- write a day and press <Enter>" << endl;
        Sleep(delay);
        cout << "Enter day(1-31): " << find_time[2] << endl;
        cout << "\nEnter hour(0-23): <- write a hour and press <Enter>" << endl;
        Sleep(delay);
        cout << "Enter hour(0-23): " << find_time[3] << endl;
        cout << "\nEnter minute(0-59): <- write a minute and press <Enter>" << endl;
        Sleep(delay);
        cout << "Enter minute(0-59): " << find_time[4] << endl;
        cout << "\nEnter second(0-59): <- write a second and press <Enter>" << endl;
        Sleep(delay);
        cout << "Enter second(0-59): " << find_time[5] << endl;
        Sleep(delay + 1000);
        write_monsters_menu(find_types_time(type, find_time, demo_monsters), demo_monsters);
        Sleep(delay + 1000);
        delete[] find_time;
    }
    void demo_read_id(int& delay, const vector<info_monster>& demo_monsters)
    {
        cout << "\nEnter id of monster: <- write the id and press <Enter>" << endl;
        Sleep(delay);
        cout << "Enter id of monster: " << demo_monsters[0].id << endl;
        Sleep(delay);
    }
    void demo_edit_monsters_menu(int& delay, vector<info_monster>& demo_monsters)
    {
        Sleep(delay);
        cout << "\nMonster:\n" << endl;
        impl::write_monster(0, demo_monsters);
        Sleep(delay);
    }
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
    void demo_mode()
    {
        int delay = 1900;
        while (true)
        {
            cout << "\nEnter a delay to display data (in milliseconds; normal = 1900): ";
            cin >> delay;
            if ((delay < 0) || (!cin.good()))
            {
                cin.clear();
                cin.ignore(200, '\n');
                cout << "\nData entered incorrectly!" << endl;
                continue;
            }
            break;
        }
        vector <info_monster> demo_monsters;
        cout << "\nThe start of the demo mode(press <Ctrl + C> to exit)" << endl;
        demo_menu(delay);
        demo_add_monster(delay, demo_monsters);
        demo_show_all_monsters(delay, demo_monsters);
        demo_find_name(delay, demo_monsters);
        demo_find_hp_damage(delay, demo_monsters);
        demo_find_types_time(delay, demo_monsters);
        demo_edit_monster(delay, demo_monsters);
        demo_delete_monster(delay, demo_monsters);
        demo_exit(delay);
        cout << "\nThe end of the demo mode" << endl;
        Sleep(1000);
    }
}