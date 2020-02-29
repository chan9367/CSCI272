#include <iostream>
#include "character.h"

Character::Character(std::string name) :char_name{ name }
{
	set_start_position();
	set_move();
}
char Character::get_ID() { return 'x'; }
std::string Character::get_name() { return char_name; }
std::string Character::get_position() {
	std::string rowcol;
	std::string cr = std::to_string(Character::row), cc = std::to_string(Character::col);
	rowcol += cr;
	rowcol += ":";
	rowcol += cc;
	return rowcol;
}
void Character::set_start_position() { Character::row = 0; Character::col = 0; }
void Character::set_move() { Character::move_horizontal=1; Character::move_vertical=1; }