#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H



class Character {
	friend class Gameboard;
  friend class Alpha;
  friend class Beta;
  friend class Gamma;
public:
	Character(std::string = "unknown player");
	virtual char get_ID() = 0;
	std::string get_name();
	std::string get_position();
	virtual void set_start_position() = 0;
	virtual void set_move() = 0;

private:
	std::string char_name;
	int row;
	int col;
	int move_horizontal;
	int move_vertical;
};







#endif
