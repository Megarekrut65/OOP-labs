#pragma once
#include <iostream>
#include "file_opening_mode.h"
#include "memory_opening_mode.h"
#include <memory>

/**
* \brief Namespace for Interactive dialog mode.
*/
namespace im//interactive mode
{
	/**
	* \brief Starts Interactive dialog mode.
	* 
	* Can choose to open and save monsters or exit.
	* 
	* Creates a pointer to selected opening mode class.
	*/
	void interactive_dialog_mode();
	/**
	* \brief Menu with all the operations that can be performed on monsters.
	* 
	* \param open - pointer to selected opening mode class
	*/
	void interactive_menu(std::shared_ptr<om::OpeningMode> open);
	/**
	* \brief Menu with all searching operations.
	* 
	* \param open - pointer to selected opening mode class
	*/
	void monster_search(std::shared_ptr<om::OpeningMode> open);
}