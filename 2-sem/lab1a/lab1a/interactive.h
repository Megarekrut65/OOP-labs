#pragma once
#include <iostream>
#include "file_opening_mode.h"
#include "memory_opening_mode.h"
#include <memory>

namespace im//interactive mode
{
	void interactive_menu(std::shared_ptr<om::OpeningMode> open);
	void monster_search(std::shared_ptr<om::OpeningMode> open);
	void interactive_dialog_mode();
}