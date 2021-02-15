#include "interactive.h"

namespace im
{
    void interactive_dialog_mode()
    {
        vector <info_monster> all_monsters;
        string txt = "text.txt", bin = "binary.bin";
        all_monsters = opening_mode(txt, bin);
        while (true)
        {
            cout << "\nMenu:\n1)Add a new monster.\n2)Show all the monsters.\n3)Find an existing monster.\n"
                << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << endl;
            switch (_getch())
            {
            case '1':
            {
                add_new_monster(all_monsters);
                continue;
            }
            break;
            case'2':
            {
                write_all_monsters(all_monsters);
                continue;
            }
            break;
            case '3':
            {
                monster_search(all_monsters);
                continue;
            }
            break;
            case '4':
            {
                edit_monster(all_monsters);
                continue;
            }
            break;
            case '5':
            {
                delete_monster(all_monsters);
                continue;
            }
            break;
            case '0':
            {
                if (!save_text_file("copy_" + txt, all_monsters) || !save_binary_file("copy_" + bin, all_monsters))
                {
                    cout << "\nError saving copy file!..." << endl;
                }
                if (all_monsters.size() == 0)
                {
                    std::remove("text.txt");
                    std::remove("binary.bin");
                    std::remove("copy_text.txt");
                    std::remove("copy_binary.bin");
                }
                all_monsters.clear();
            }
            break;
            default:
            {
                cout << "\nPress the correct key!" << endl;
                continue;
            }
            }
            break;
        }
    }
    void monster_search(const vector<info_monster>& all_monsters)
    {
        while (true)
        {
            cout << "\nSelect Monster Search Mode:\n1)Search by Name.\n2)Search by hp and damage.\n"
                << "3)Search by type of special monster attack and date." << endl;
            switch (_getch())
            {
            case '1': find_name_menu(all_monsters);
                break;
            case '2': find_hp_damage_menu(all_monsters);
                break;
            case '3': find_types_time_menu(all_monsters);
                break;
            default:
            {
                cout << "\nPress the correct key!" << endl;
                continue;
            }
            }
            break;
        }
    }
    vector<info_monster> opening_mode(const string& txt, const string& bin)
    {
        while (true)
        {
            cout << "\nSelect the opening mode:\n1)Text mode.\n2)Binary mode." << endl;
            switch (_getch())
            {
            case '1':  return open_text_file(txt);
                break;
            case '2':  return open_binary_file(bin);
                break;
            default:
            {
                cout << "\nPress the correct key!" << endl;
                continue;
            }
            }
            break;
        }
    }
}