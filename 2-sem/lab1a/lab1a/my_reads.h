#pragma once
#include <string>
#include <iostream>
#include "monster.h"
#include <conio.h>

/**
* \brief Namespace for functions of correct read.
*/
namespace mrs//my reads
{
	/**
	* \brief Same of all read functions.
	* 
	* Prints to display information about right data to enter.
	* 
	* \param sentence - information about right data
	*/
	void same_part(const std::string& sentence);
	/**
	* \brief Clears buffer.
	*/
	void clear();
	/**
	* \brief Prints information about incorrect entered data.
	*/
	void data_incorrect();
	/**
	* \brief Create string of the valid input area.
	* 
	* \param min - the beginning of the interval
	* \param max - the end of the interval
	* \returns string valid input area
	*/
	template<typename T>
	std::string min_max_part(T min, T max);
	/**
	* \brief Reads a number with value from min to max.
	* 
	* The function will not complete until the correct data is entered.
	* 
	* \param sentence - data to print
	* \param min - the beginning of the interval
	* \param max - the end of the interval
	* \returns correct number
	*/
	std::size_t read_size_t(const std::string& sentence, 
		std::size_t min = std::numeric_limits<std::size_t>::min(), 
		std::size_t max = std::numeric_limits<std::size_t>::max());
	/**
	* \brief Reads a double number with value from min to max.
	*
	* The function will not complete until the correct data is entered.
	*
	* \param sentence - data to print
	* \param min - the beginning of the interval
	* \param max - the end of the interval
	* \returns correct double number
	*/
	double read_double(const std::string& sentence,
		double min = std::numeric_limits<double>::min(),
		double max = std::numeric_limits<double>::max());
	/**
	* \brief Reads a line with size from min to max.
	*
	* The function will not complete until the correct data is entered.
	*
	* \param sentence - data to print
	* \param min - the beginning of the interval
	* \param max - the end of the interval
	* \returns non-empty line
	*/
	std::string read_string(const std::string& sentence, 
		std::size_t min = std::numeric_limits<std::size_t>::min(), 
		std::size_t max = std::numeric_limits<std::size_t>::max());
	/**
	* \brief Function to choose one of four types of attack (mon::AttackTypes).
	* 
	* \returns type of attack
	*/
	mon::AttackTypes read_type();
}