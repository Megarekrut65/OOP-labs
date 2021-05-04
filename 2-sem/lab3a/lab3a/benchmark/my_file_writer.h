#include <iostream>
#include <fstream>

/**
*	\brief Namespace for class FileWriter
*/
namespace fwriter
{
	/**
	*	\brief Class for adding to file some strings
	*/
	class FileWriter
	{
	private:
		std::string path;/**< Path to file*/
	public:
		/**
		*	\brief Paramatrized constructor
		* 
		*	\param path - path to file
		*/
		FileWriter(const std::string& path = "output.txt");
		/**
		*	\brief Append value to end of file
		*/
		void append(const std::string& value);
		/**
		*	\brief Clears file
		*/
		void clear();
		/**
		*	\brief Writes to console information of file path
		*/
		void info();
	};
}