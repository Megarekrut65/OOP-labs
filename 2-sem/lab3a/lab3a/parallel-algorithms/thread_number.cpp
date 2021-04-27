#pragma once
#include "thread_number.h"
namespace thnum
{
	ThNumber::ThNumber():number{0}{}
	bool ThNumber::add_new_thread()
	{
		std::lock_guard<std::mutex> lock(mut);
		std::cout << "max th=" << std::thread::hardware_concurrency() << std::endl;
		if (number < std::thread::hardware_concurrency())
		{
			number++;
			std::cout << "id=" << std::this_thread::get_id() << " number=" << number << std::endl;
			return true;
		}
		
		return false;
	}
}