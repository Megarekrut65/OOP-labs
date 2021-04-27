#pragma once
#include "thread_number.h"
namespace thnum
{
	ThdNumber::ThdNumber():number{0}{}
	bool ThdNumber::increase()
	{
		std::lock_guard<std::mutex> lock(mut);
		if (number < std::thread::hardware_concurrency())
		{
			number++;
			return true;
		}
		
		return false;
	}
	void ThdNumber::decrease()
	{
		std::lock_guard<std::mutex> lock(mut);
		if (number > 0) number--;
		else throw std::out_of_range{"Number can not be less than 0!"};
	}
}