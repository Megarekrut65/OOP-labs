#pragma once
#include "thread_number.h"
namespace thnum
{
	ThdNumber::ThdNumber():number{0}{}
	bool ThdNumber::add_new_thread()
	{
		std::lock_guard<std::mutex> lock(mut);
		if (number < std::thread::hardware_concurrency())
		{
			number++;
			return true;
		}
		
		return false;
	}
}