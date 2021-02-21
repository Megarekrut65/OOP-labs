#include "monster_menu.h"

namespace mmenu
{
	void menu()
	{
        std::cout << "<The Forest of Monsters>" << std::endl;
        while (true)
        {
            std::cout << "\nSelect the application mode:\n1)Interactive dialog mode.\n"
                << "2)Demo mode.\n3)Automatic benchmark mode.\n0)Exit.\n";
            switch (_getch())
            {
            case '1': im::interactive_dialog_mode();
                break;
            case '2':
            {
                dm::DemoMode demo_mode(std::make_shared<mmode::MemoryMode>(), 2000);
                demo_mode.start();
            }
                break;
            case '3':
            {
                bm::BenchmarkMode benchmark;
                benchmark.start();
            }
                break;
            case'0':
            {
                std::cout << "\nExit..." << std::endl;
                return;
            }
            break;
            default: std::cout << "\nPress the correct key!" << std::endl;
            }
        }
	}
}