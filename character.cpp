#include <iostream>
#include "character.h"

Character::Character(std::string name) :char_name{ name }
{
}
std::string Character::get_name() { return char_name; }
std::string Character::get_position() {
	std::string rowcol;
	std::string cr = std::to_string(Character::row), cc = std::to_string(Character::col);
	rowcol += cr;
	rowcol += ":";
	rowcol += cc;
	return rowcol;
}