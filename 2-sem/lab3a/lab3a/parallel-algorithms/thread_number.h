#pragma once
#include <thread>
#include <mutex>
#include <iostream>
/**
* \brief Thread number
*/
namespace thnum
{
	class ThreadNumber
	{
	private:
		std::size_t number;
		std::mutex mut;
	public:
		ThreadNumber();
		bool add_new_thread();
	};
}