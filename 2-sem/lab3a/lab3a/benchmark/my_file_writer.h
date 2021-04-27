#include <iostream>
#include <fstream>

namespace fwriter
{
	class FileWriter
	{
	private:
		std::string path;
	public:
		FileWriter(const std::string& path = "output.txt");
		void append(const std::string& value);
		void clear();
		void info();
	};
}