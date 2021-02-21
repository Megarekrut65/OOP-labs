#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <stdio.h>

/**
* \brief Namespace for auxiliary functions for files.
*/
namespace ffs//file functions
{
	/**
	* \brief Creates a text file if it does not exist.
	* 
	* \param path - path to file
	* \param in_mode - input mode
	* \param out_mode - output mode
	*/
	void check_for_file(std::string path, 
		std::ios_base::_Openmode in_mode, 
		std::ios_base::_Openmode out_mode);
	/**
	* \brief Function for correct reading line from text file.
	* 
	* Skips blank lines.
	* \param file - input stream
	* \returns a data string
	*/
	std::string line_read(std::ifstream& file);
	/**
	* \brief Renames first file and deletes second one.
	* 
	* Firstly second file will be deleted and than the name of first file 
	* will be like name of second one.
	* 
	* If will be some errors then will be message about it.
	* 
	* \param ren - file to rename
	* \param del - file to delete
	*/
	void file_rename_delete(std::string ren, std::string del);
}