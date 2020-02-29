#include <string>
#include "character.h"

#ifndef ALPHA_H
#define ALPHA_H

class Alpha : public Character{


  public:
	Alpha(std::string = "player alpha");
	char get_ID();
	void set_start_position();
	void set_move();
  
};




#endif

