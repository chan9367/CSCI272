#include <string>
#include "character.h"

#ifndef BETA_H
#define BETA_H

class Beta : public Character{


  public:
	Beta(std::string = "player beta");
	char get_ID();
	void set_start_position();
	void set_move();
  
};




#endif

