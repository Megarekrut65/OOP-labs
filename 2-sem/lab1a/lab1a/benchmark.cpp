#include "benchmark.h"

namespace bm
{
    BenchmarkMode::BenchmarkMode()
        : number_of_functions(7), open(nullptr),
        name_of_functions({"add_monster", "edit_monster", "delete_monster",
            "find_name", "find_hp_damage", "find_type_time"}), 
        inizial_monster_number(10), current_monster_number(0), 
        saved_monster_number(0), text_path("ben_text.txt"),
        binary_path("ben_binary.bin"), current_id(1000) {}
    void BenchmarkMode::start()
    {
        clear_result_files();
        float function_time;
        bool more_than_one = false, more_than_ten = false;
        std::size_t coefficient = 2;
        while (true)
        {
            for (unsigned i = 0; i < number_of_monsters; i++)
            {
                monster_generator(all_monsters);
            }
            cout << "\n\nN = " << number_of_monsters << endl;
            for (unsigned j = 0; j < number_of_function; j++)
            {
                function_time = arr_pointers_to_functions[j](all_monsters);
                if (function_time >= 1) time_is_more_than_second = true;
                if (function_time > 10) time_is_more_than_ten_seconds = true;
            }
            if (time_is_more_than_ten_seconds) break;
            if (time_is_more_than_second) number_of_monsters = number_of_monsters_for_progression * coefficient++;
            else
            {
                number_of_monsters *= 2;
                number_of_monsters_for_progression = number_of_monsters;
            }
        }
        finish();
    }
    void BenchmarkMode::finish()
    {
        std::cout << "\nResults of measurements of program in the following files:" << std::endl;
           
        std::remove(text_path);
        std::remove(binaty_path);
    }
    mon::Monster BenchmarkMode::get_random_monster()
    {
        srand(unsigned(time(0)));
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
       for(std::size_t i = 0; i < current_monster_number; i++)
            open->append_monster(get_random_monster());
    }
    void BenchmarkMode::add_result_to_file(const std::string& path,
        const MeasurementResult& result, bool is_size)//the function adds the measurement result to a text file
    {
        std::ofstream file(path, std::ios_base::app);
        file << "Number: " << result.number_of_monsters << std::endl;
        file << "Time: " << result.time << std::endl;
        if (is_size) file << "Size file:" << result.size << std::endl << std::endl;
        file.close();
    }
    void BenchmarkMode::all_functions(std::size_t index, mon::Monster monster)
    {
        switch (index)
        {
        case 1: open->append_monster(get_random_monster());
            break;
        case 2: open->save_edited_monster(monster);
            break;
        case 3: open->save_edited_monster(monster);
            break;
        case 4: open->find_name(monster.get_name());
            break;
        case 5: open->find_hp_damage(monster.get_hp(), monster.get_damage());
            break;
        case 6: open->find_types_time(monster.get_type(), om::OpeningMode::tm_to_vector(monster.get_time()));
            break;
        default:
            break;
        }
    }
    float BenchmarkMode::measurement(const std::string& result_path, std::size_t index)//the function measures the opening time of a text file
    {
        MeasurementResult result;
        result.number_of_monsters = current_monster_number;
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        mon::Monster monster = open->get_monster(--current_id);
        the_start = std::chrono::high_resolution_clock::now();
        all_functions(index, monster);
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        result.time = duration.count();
        add_result_to_file(result_path + ".txt", result);
        std::cout << "Time of " + result_path +" = " << result.time << " seconds." << std::endl;
        return result.time;
    }
    void BenchmarkMode::clear_result_files()//function clears old result files
    {
        for (std::size_t i = 0; i < number_of_functions; i++)
        {
            std::ofstream clear_file(name_of_functions[i] + ".txt");
            clear_file.close();
        }
    }
}