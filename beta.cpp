#include <iostream>
#include "beta.h"

Beta::Beta(std::string name) :Character(name)
{
	set_start_position();
	set_move();
}
char Beta::get_ID() { return 'b'; }
void Beta::set_start_position() { Character::row=1; Character::col=2; }
void Beta::set_move() { Character::move_horizontal=3; Character::move_vertical=4; }
