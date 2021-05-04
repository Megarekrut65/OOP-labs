#pragma once
#include <thread>
#include <mutex>
#include <iostream>
/**
* \brief Thread number
*/
namespace thnum
{
	/**
	*	\brief Class for saving and editing number of opened threads
	*/
	class ThdNumber
	{
	private:
		std::size_t number;/**< Number of opened threads */
		std::mutex mut;/**< Mutex for thread locking */
	public:
		/**
		*	\brief Default constructor
		*/
		ThdNumber();
		/**
		*	\brief Adds opened thread
		* 
		*	If OS can open more threads than returns trueand increase number of threads 
		*	else return false.
		*/
		bool increase();
		/**
		*	\brief Removes opened thread
		* 
		*	If there are not any opened threads than will be error
		*/
		void decrease();
	};
}