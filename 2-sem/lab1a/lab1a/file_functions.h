#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>

namespace ffs//file functions
{
	bool check_for_file(std::string path, std::ios_base::_Openmode in_mode, std::ios_base::_Openmode out_mode);//the function creates a text file if it does not exist
	std::string line_read(std::ifstream& file);
	void file_rename_delete(std::string ren, std::string del);
}