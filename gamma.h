#include <string>
#include "character.h"

#ifndef GAMMA_H
#define GAMMA_H

class Gamma : public Character{


  public:
	Gamma(std::string = "player gamma");
	char get_ID();
	void set_start_position();
	void set_move();
  
};




#endif

