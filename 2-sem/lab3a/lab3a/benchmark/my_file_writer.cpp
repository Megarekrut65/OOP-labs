#include "my_file_writer.h"

namespace fwriter
{
	FileWriter::FileWriter(const std::string& path)
		:path{ path } {}
	void FileWriter::append(const std::string& value)
	{
		std::ofstream file(path, std::ios_base::app);
		file << value << std::endl;
		file.close();
	}
	void FileWriter::clear()
	{
		std::ofstream file(path);
		file.close();
	}
	void FileWriter::info()
	{
		std::cout << "\nResults of measurements of program is" <<
			" in the following file:\n" << path << std::endl;
	}
}