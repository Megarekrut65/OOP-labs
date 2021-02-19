#include "benchmark.h"

namespace bm
{
    BenchmarkMode::BenchmarkMode(): open(nullptr) {}
   /* void BenchmarkMode::start()
    {
        clear_result_files();
        unsigned number_of_monsters, number_of_monsters_for_progression = 1;
        while (true)
        {
            cout << "\nEnter the initial number of monsters(1-...): ";
            cin >> number_of_monsters;
            if ((number_of_monsters < 1) || (!cin.good()))
            {
                cin.clear();
                cin.ignore(200, '\n');
                cout << "\nData entered incorrectly!" << endl;
                continue;
            }
            break;
        }
        vector <info_monster> all_monsters;
        float function_time;
        const int number_of_function = 7;
        float (*arr_pointers_to_functions[number_of_function])(vector<info_monster>&) = { measurement_save_txt,
            measurement_save_bin, measurement_open_txt, measurement_open_bin ,measurement_name_find,
            measurement_hp_damage_find, measurement_time_type_find };
        bool time_is_more_than_second = false, time_is_more_than_ten_seconds = false;
        unsigned coefficient = 2;
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
        cout << "\nResults of measurements of program in the following files:\n"
            << "result_save_txt_file.txt\nresult_open_txt_file.txt\n"
            << "result_save_binary_file.txt\nresult_open_binary_file.txt\n"
            << "result_name_find.txt\nresult_xp_damage_find.txt\nresult_time_type_find.txt" << endl;
        std::remove("benchmark_text.txt");
        std::remove("benchmark_binary.bin");
    }*/
    void BenchmarkMode::monster_generator()//the function creates a monster with random parameters
    {
        srand(unsigned(time(0)));
        std::size_t name_size = (rand() % 10 + 5);
        std::string name(name_size, 'a');
        for (std::size_t i = 0; i < name_size; i++)
        {
            name[i] = 'a' + (rand() % 26);
        }
        unsigned hp = (rand() % 50000 + 1);
        unsigned damage = (rand() % 1000 + 1);
        double chance = 0.01 * double(rand() % 101);
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
        open->append_monster(
            mon::Monster(name, hp, damage, chance, type, 
                open->get_time_now(), current_id++));
    }
    std::size_t BenchmarkMode::size_file(const std::string& path)
    {
        std::ifstream file(path);
        file.seekg(0, std::ios_base::end);
        std::size_t sizef = size_t(file.tellg());
        file.close();

        return sizef;
    }
    void BenchmarkMode::add_program_test(const std::string& path,
        const MeasurementResult& result, bool is_size)//the function adds the measurement result to a text file
    {
        std::ofstream file(path, std::ios_base::app);
        file << "Number: " << result.number_of_monsters << std::endl;
        file << "Time: " << result.time << std::endl;
        if (is_size) file << "Size file:" << result.size << std::endl << std::endl;
        file.close();
    }
    /*
    float measurement_open_txt(vector<info_monster>& all_monsters)//the function measures the opening time of a text file
    {
        measurement_result open_txt;
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        open_txt.number_of_monsters = all_monsters.size();
        the_start = std::chrono::high_resolution_clock::now();
        all_monsters = open_text_file("benchmark_text.txt");
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        open_txt.time = duration.count();
        add_program_test("result_open_txt_file.txt", open_txt, false);
        cout << "Time of open txt = " << open_txt.time << " seconds." << endl;
        all_monsters.clear();

        return open_txt.time;
    }
    float measurement_open_bin(vector<info_monster>& all_monsters)//the function measures the opening time of a binary file
    {
        measurement_result open_bin;
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        open_bin.number_of_monsters = all_monsters.size();
        the_start = std::chrono::high_resolution_clock::now();
        all_monsters = open_binary_file("benchmark_binary.bin");
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        open_bin.time = duration.count();
        add_program_test("result_open_binary_file.txt", open_bin, false);
        cout << "Time of open binary = " << open_bin.time << " seconds." << endl;

        return open_bin.time;
    }
    float measurement_save_txt(vector<info_monster>& all_monsters)//the function measures the storage time of a text file and its size
    {
        measurement_result save_txt;
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        save_txt.number_of_monsters = all_monsters.size();
        the_start = std::chrono::high_resolution_clock::now();
        save_text_file("benchmark_text.txt", all_monsters);
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        save_txt.time = duration.count();
        save_txt.size = size_file("benchmark_text.txt");
        add_program_test("result_save_txt_file.txt", save_txt);
        cout << "Time of save txt = " << save_txt.time << " seconds." << endl;
        cout << "Size of save txt = " << save_txt.size << " bytes." << endl;

        return save_txt.time;
    }
    float measurement_save_bin(vector<info_monster>& all_monsters)//the function measures the storage time of a binary file and its size
    {
        measurement_result save_bin;
        save_bin.number_of_monsters = all_monsters.size();
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        the_start = std::chrono::high_resolution_clock::now();
        save_binary_file("benchmark_binary.bin", all_monsters);
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        save_bin.time = duration.count();
        save_bin.size = size_file("benchmark_binary.bin");
        add_program_test("result_save_binary_file.txt", save_bin);
        cout << "Time of save binary = " << save_bin.time << " seconds." << endl;
        cout << "Size of save binary = " << save_bin.size << " bytes." << endl;
        all_monsters.clear();
        return save_bin.time;
    }
    float measurement_name_find(vector<info_monster>& all_monsters)//the function measures the search time of a monster in a file
    {
        measurement_result name_find;
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        name_find.number_of_monsters = all_monsters.size();
        string name = all_monsters[name_find.number_of_monsters - 1].name;
        vector <int> number;
        the_start = std::chrono::high_resolution_clock::now();
        number = find_name(name, all_monsters);
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        name_find.time = duration.count();
        add_program_test("result_name_find.txt", name_find, false);
        cout << "Time of find by name = " << name_find.time << " seconds." << endl;

        return name_find.time;
    }
    float measurement_hp_damage_find(vector<info_monster>& all_monsters)//the function measures the search time of a monster in a file
    {
        measurement_result xp_damage_find;
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        xp_damage_find.number_of_monsters = all_monsters.size();
        unsigned hp = all_monsters[xp_damage_find.number_of_monsters - 1].hp;
        unsigned damage = all_monsters[xp_damage_find.number_of_monsters - 1].damage;
        vector <int> number;
        the_start = std::chrono::high_resolution_clock::now();
        number = find_hp_damage(hp, damage, all_monsters);
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        xp_damage_find.time = duration.count();
        add_program_test("result_xp_damage_find.txt", xp_damage_find, false);
        cout << "Time of find by xp and damage = " << xp_damage_find.time << " seconds." << endl;

        return xp_damage_find.time;
    }
    float measurement_time_type_find(vector<info_monster>& all_monsters)//the function measures the search time of a monster in a file
    {
        measurement_result time_type_find;
        auto the_start = std::chrono::high_resolution_clock::now();
        auto the_end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration;
        time_type_find.number_of_monsters = all_monsters.size();
        vector <int> number;
        types_of_attack type = all_monsters[time_type_find.number_of_monsters - 1].type_of_attack;
        int time[6] = { 2021,12,28,23,59,59 };
        the_start = std::chrono::high_resolution_clock::now();
        number = find_types_time(type, time, all_monsters);
        the_end = std::chrono::high_resolution_clock::now();
        duration = the_end - the_start;
        time_type_find.time = duration.count();
        add_program_test("result_time_type_find.txt", time_type_find, false);
        cout << "Time of find by types of attack and time = " << time_type_find.time << " seconds." << endl;
        all_monsters.clear();

        return time_type_find.time;
    }
    void clear_result_files()//function clears old result files
    {
        string all_result_files[7] = { "result_save_txt_file.txt", "result_save_binary_file.txt",
            "result_open_txt_file.txt", "result_open_binary_file.txt", "result_name_find.txt",
            "result_xp_damage_find.txt", "result_time_type_find.txt" };
        for (unsigned i = 0; i < 7; i++)
        {
            std::ofstream clear_file(all_result_files[i]);
            clear_file.close();
        }
    }*/
}