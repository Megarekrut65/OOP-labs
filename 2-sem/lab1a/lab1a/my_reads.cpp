#include "my_reads.h"

namespace mrs
{
    void same_part(const std::string& sentence)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "\nEnter " << sentence << ": ";
    }
    void data_incorrect()
    {
        std::cout << "\nThe data entered incorrectly!" << std::endl;
    }
	std::size_t read_size_t(const std::string& sentence, std::size_t min, std::size_t max )
	{
        while (true)
        {
            same_part(sentence);
            std::size_t number;
            std::cin >> number;
            if (std::cin.fail() || number < min || number > max) data_incorrect();
            else return number;           
        }
	}
    double read_double(const std::string& sentence, double min, double max)
    {
        while (true)
        {
            same_part(sentence);
            std::string line = "";
            while (line.size() == 0) getline(std::cin, line);
            char* fails;
            double number;
            if (line.find(",") != std::string::npos)
                line.replace(line.find(","), 1, ".");           
            number = strtod(line.c_str(), &fails);
            if (*fails != 0 || number < min || number > max) data_incorrect();             
            else return number;
        }
    }
    std::string read_string(const std::string& sentence, std::size_t min, std::size_t max)
    {  
        while (true)
        {
            same_part(sentence);
            std::string line = "";
            while (line.size() == 0) getline(std::cin, line);
            if (line.size() < min || line.size() > max) data_incorrect();
            else return line;
        }      
    }
    im::AttackTypes read_type()
    {
        while (true)
        {
            std::cout << "\nChoose one of the possible types of special monster attack:\n"
                <<"1)Increase damage.\n" << "2)Repeat the attack.\n3)Cure yourself.\n"
                <<"4)Paralyze the enemy." << std::endl;
            switch (_getch())
            {
            case '1': return im::AttackTypes::INCREASE;
            case '2': return im::AttackTypes::REPEAT;
            case '3': return im::AttackTypes::CURE;
            case '4': return im::AttackTypes::PARALYZE;
            default: std::cout << "\nPress the correct key!" << std::endl;
            }
        }
    }
}