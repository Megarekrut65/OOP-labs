#pragma once
#include <thread>
#include <mutex>
#include <iostream>
/**
* \brief Thread number
*/
namespace thnum
{
	class ThdNumber
	{
	private:
		std::size_t number;
		std::mutex mut;
	public:
		ThdNumber();
		bool increase();
		void decrease();
	};
}