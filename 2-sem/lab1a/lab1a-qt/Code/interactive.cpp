#include "interactive.h"

namespace im
{
    void interactive_menu(std::shared_ptr<om::OpeningMode> open)
    {
        while (true)
        {
            std::cout << "\nMenu:\n1)Add a new monster.\n"
                <<"2)Show all monsters.\n3)Find an existing monster.\n"
                << "4)Edit a monster.\n5)Delete a monster.\n0)Back." << std::endl;
            switch (_getch())
            {
            case '1': open->add_new_monster();
                break;
            case '2':open->write_all_monsters();
                break;
            case '3':monster_search(open);
                break;
            case '4':open->edit_monster();
                break;
            case '5':open->delete_monster();
                break;
            case '0': return;
                break;
            default: std::cout << "\nPress the correct key!" << std::endl;
                break;
            }
        }
    }
    void monster_search(std::shared_ptr<om::OpeningMode> open)
    {
        while (true)
        {
            std::cout << "\nSelect Monster Search Mode:\n"
                <<"1)Search by Name.\n2)Search by hp and damage.\n"
                << "3)Search by type of special monster attack and date.\n"
                <<"0)Back."<< std::endl;
            switch (_getch())
            {
            case '1': open->find_name_menu();
                break;
            case '2': open->find_hp_damage_menu();
                break;
            case '3': open->find_types_time_menu();
                break;
            case '0': return;
                break;
            default: std::cout << "\nPress the correct key!" << std::endl;
                break;
            }
        }
    }
    void interactive_dialog_mode()
    {
        std::shared_ptr<om::OpeningMode> open;
        const std::string path = "monsters.";
        while (true)
        {
            std::cout << "\nSelect the opening mode:\n"<<
                "1)Memory mode.\n2)Text mode.\n3)Binary mode.\n0)Back." << std::endl;
            switch (_getch())
            {
            case '1': open = std::make_shared<mmode::MemoryMode>();           
                break;
            case '2':  
            {
                std::string the_path = path + "txt";
                open = std::make_shared<fmode::FileMode>(the_path, omode::Mode::TEXT );             
            }
                break;
            case '3':
            {
                std::string the_path = path + "bin";
                open = std::make_shared<fmode::FileMode>(the_path, omode::Mode::BINARY);
            }
            break;
            case '0': return;
                break;
            default:
            {
                std::cout << "\nPress the correct key!" << std::endl;
                continue;
            }
                break;
            }
            interactive_menu(open);
            return;
        }
    }
}
