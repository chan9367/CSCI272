#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H



class Character {
	friend class Gameboard;
public:
	Character(std::string = "unknown player");
	char get_ID();
	std::string get_name();
	std::string get_position();
	void set_start_position();
	void set_move();

private:
	std::string char_name;
	int row;
	int col;
	int move_horizontal;
	int move_vertical;
};







#endif
