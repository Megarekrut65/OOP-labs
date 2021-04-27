#pragma once
#include <thread>
#include <mutex>
#include <iostream>
/**
* \brief Thread number
*/
namespace thnum
{
	class ThNumber
	{
	private:
		std::size_t number;
		std::mutex mut;
	public:
		ThNumber();
		bool add_new_thread();
	};
}