#pragma once
#include <string>
#include <iostream>
#include "monster.h"
#include <conio.h>

namespace mrs//my reads
{
	void same_part(const std::string& sentence);
	void data_incorrect();
	template<typename T>
	std::string min_max_part(T min, T max);
	std::size_t read_size_t(const std::string& sentence, 
		std::size_t min = std::numeric_limits<std::size_t>::min(), 
		std::size_t max = std::numeric_limits<std::size_t>::max());
	double read_double(const std::string& sentence,
		double min = std::numeric_limits<double>::min(),
		double max = std::numeric_limits<double>::max());
	std::string read_string(const std::string& sentence, 
		std::size_t min = std::numeric_limits<std::size_t>::min(), 
		std::size_t max = std::numeric_limits<std::size_t>::max());
	mon::AttackTypes read_type();
}