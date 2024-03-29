#include "file_functions.h"

namespace ffs
{
    void check_for_file(std::string path, std::ios_base::openmode in_mode,
        std::ios_base::openmode out_mode)
    {
        std::ifstream file(path, in_mode);
        if (!file.is_open())
        {
            file.close();
            std::ofstream file_create(path, out_mode);
            file_create.close();
        }
        else file.close();
    }
    std::string line_read(std::ifstream& file)
    {
        std::string line = "";
        getline(file, line);
        while (line.size() == 0)
        {
            if (file.eof()) break;
            getline(file, line);
        }

        return line;
    }
    void file_rename_delete(std::string ren, std::string del)
    {
        if (remove(del.c_str()) != 0) 
            std::cerr << "Error with deleting file '" << del << "'!" << std::endl;
        if(rename(ren.c_str(), del.c_str()) != 0) 
            std::cerr << "Error with renaming files '" << ren << "' and '" << del << "'!" << std::endl;
    }
}
