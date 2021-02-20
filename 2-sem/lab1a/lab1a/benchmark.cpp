#include "benchmark.h"

namespace bm
{
    BenchmarkMode::BenchmarkMode(std::size_t inizial_monster_number)
        : number_of_functions(6), open(nullptr),name_of_open(""), folder_name("results/"),
        name_of_functions({"add_monster", "edit_monster", "delete_monster",
            "find_name", "find_hp_damage", "find_type_time"}), 
        inizial_monster_number(inizial_monster_number), current_monster_number(0),
        prev_monster_number(0), saved_monster_number(0), text_path("ben_text.txt"),
        binary_path("ben_binary.bin"), current_id(1000) {}
    void BenchmarkMode::testing()
    {
        before_testing();
        float function_time = 0.f;
        bool more_than_one = false, more_than_ten = false;
        std::size_t coefficient = 2;
        while (true)
        {
            monster_generator();
            prev_monster_number = current_monster_number;
            std::cout << "\n\nNumber of monsters = "
                << current_monster_number << std::endl;
            class_size_of(name_of_open + "size_of.txt");
            for (std::size_t i = 0; i < number_of_functions; i++)
            {
                function_time = measurement(i);
                if (function_time >= 1) more_than_one = true;
                if (function_time > 10) more_than_ten = true;
            }
            if (more_than_ten) break;
            new_number(more_than_one, coefficient);
        }
        finish();
    }
    void BenchmarkMode::before_start()
    {
        srand(unsigned(time(0)));
        std::ofstream file1(text_path.c_str());
        file1.close();
        std::ofstream file2(binary_path.c_str());
        file2.close();
    }
    void BenchmarkMode::set_memory_mode()
    {
        open = std::make_shared<mmode::MemoryMode>();
        name_of_open = folder_name + "memory_";
        std::cout << "\nTesting of memory mode...\n" << std::endl;
    }
    void BenchmarkMode::set_text_mode()
    {
        open = std::make_shared<fmode::FileMode>(text_path, omode::Mode::TEXT);
        name_of_open = folder_name + "text_";
        std::cout << "\nTesting of text mode...\n" << std::endl;
    }
    void BenchmarkMode::set_binary_mode()
    {
        open = std::make_shared<fmode::FileMode>(binary_path, omode::Mode::BINARY);
        name_of_open = folder_name + "binary_";
        std::cout << "\nTesting of binary mode...\n" << std::endl;
    }
    void BenchmarkMode::start()
    {
        before_start();
        while (true)
        {
            std::cout << "\nChoose one:\n1)Testing memory mode.\n"
                << "2)Testing text mode.\n3)Testing binary mode.\n0)Back." << std::endl;
            switch (_getch())
            {
            case '1': set_memory_mode();
                break;
            case '2': set_text_mode();
                break;
            case '3': set_binary_mode();
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
            testing();
        }              
    }
    void BenchmarkMode::new_number(bool more_than_one, std::size_t& coefficient)
    {
        if (more_than_one) 
            current_monster_number = saved_monster_number * coefficient++;
        else
        {
            current_monster_number *= 2;
            saved_monster_number = current_monster_number;
        }
    }
    void BenchmarkMode::finish()
    {
        std::cout << "\nResults of measurements of program in the following files:" << std::endl;           
        for (std::size_t i = 0; i < number_of_functions; i++)
            std::cout << name_of_open + name_of_functions[i] + ".txt" << std::endl;
        std::cout << name_of_open + "size_of.txt" << std::endl;
        std::remove(text_path.c_str());
        std::remove(binary_path.c_str());
    }
    mon::Monster BenchmarkMode::get_random_monster()
    {      
        std::size_t name_size = (rand() % 10 + 5);
        std::string name(name_size, 'a');
        for (std::size_t i = 0; i < name_size; i++)
        {
            name[i] = 'a' + (rand() % 26);
        }
        mon::AttackTypes type = mon::AttackTypes::INCREASE;
        int index = (rand() % 4 + 1);
        switch (index)
        {
        case 1: type = mon::AttackTypes::INCREASE;
            break;
        case 2: type = mon::AttackTypes::REPEAT;
            break;
        case 3: type = mon::AttackTypes::CURE;
            break;
        case 4: type = mon::AttackTypes::PARALYZE;
            break;
        }
        return mon::Monster(name, rand() % 50000 + 1,
            rand() % 1000 + 1, 0.01 * double(rand() % 101), type, 
            open->get_time_now(), current_id++);
    }
    void BenchmarkMode::monster_generator()//the function creates a monster with random parameters
    {
       for(std::size_t i = 0; i < current_monster_number - prev_monster_number; i++)
            open->append_monster(get_random_monster());
    }
    void BenchmarkMode::add_result_to_file(const std::string& path,float time)//the function adds the measurement result to a text file
    {
        std::ofstream file(path, std::ios_base::app);
        file << "Number: " << current_monster_number << std::endl;
        file << "Time: " << time << std::endl;
        file.close();
    }
    void BenchmarkMode::class_size_of(const std::string& path)
    {
        std::ofstream file(path, std::ios_base::app);
        file << "Number: " << current_monster_number << std::endl;
        std::size_t size = open->get_size_of();
        file << "Size_of: " << size << std::endl;
        std::cout << "Size_of = " << size << std::endl;
        file.close();
    }
    void BenchmarkMode::all_functions(std::size_t index, mon::Monster monster)
    {
        switch (index)
        {
        case 0: open->append_monster(get_random_monster());
            break;
        case 1: open->save_edited_monster(monster);
            break;
        case 2: open->delete_the_monster(monster);
            break;
        case 3: open->find_name(monster.get_name());
            break;
        case 4: open->find_hp_damage(monster.get_hp(), monster.get_damage());
            break;
        case 5: open->find_types_time(monster.get_type(), om::OpeningMode::tm_to_vector(monster.get_time()));
            break;
        default:
            break;
        }
    }
    float BenchmarkMode::measurement(std::size_t index)//the function measures the opening time of a text file
    {
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        mon::Monster monster = mon::Monster("1",1,1,1,mon::AttackTypes::INCREASE, open->get_time_now(), current_id * 2);
        the_start = std::chrono::high_resolution_clock::now();
        all_functions(index, monster);
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        float time = duration.count();
        add_result_to_file(name_of_open + name_of_functions[index] + ".txt", time);
        std::cout << "Time of " + name_of_functions[index] +" = " << time << " seconds." << std::endl;
        return time;
    }
    void BenchmarkMode::before_testing()//function clears old result files
    {
        current_id = 1000;
        prev_monster_number = 0;
        current_monster_number = inizial_monster_number;
        saved_monster_number = inizial_monster_number;
        for (std::size_t i = 0; i < number_of_functions; i++)
        {
            std::ofstream clear_file(name_of_open + name_of_functions[i] + ".txt");
            clear_file.close();
        }
        std::ofstream clear_file(name_of_open + "size_of.txt");
        clear_file.close();
    }
}