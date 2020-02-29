#include <iostream>
#include "alpha.h"

Alpha::Alpha(std::string name) :Character(name)
{
	set_start_position();
	set_move();
}
char Alpha::get_ID() { return 'a'; }
void Alpha::set_start_position() { Character::row=0; Character::col=3; }
void Alpha::set_move() { Character::move_horizontal=2; Character::move_vertical=5; }
