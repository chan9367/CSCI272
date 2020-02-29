#include <iostream>
#include "gamma.h"

Gamma::Gamma(std::string name) :Character(name)
{
	set_start_position();
	set_move();
}
char Gamma::get_ID() { return 'c'; }
void Gamma::set_start_position() { Character::row=0; Character::col=1; }
void Gamma::set_move() { Character::move_horizontal=3; Character::move_vertical=5; }
