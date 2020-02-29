#include "gameboard.h"
#include "character.h"
#include "alpha.h"
#include "beta.h"
#include "gamma.h"
#include <iostream>

int main() {
  
  Gameboard board{"GAME-BOARD"}; // create board
  Alpha playerA{"Player A"}; // create character
  Beta playerB{"Player B"};
  Gamma playerC{"Player C"};
  board.addPlayer(&playerA); // add player to board
  board.addPlayer(&playerB);
  board.addPlayer(&playerC);
  board.display(); // show board

  for (int i = 1; i <= 10; i++){ // 10 moves
    board.update(); // move all players
    board.display(); // show the updated board
  }
}