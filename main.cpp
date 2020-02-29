#include "gameboard.h"
#include "character.h"
#include <iostream>

int main() {
  
  Gameboard board{"GAME-BOARD"}; // create board
  Character player1{"Player1"}; // create character 
  board.addPlayer(&player1); // add player to board
  board.display(); // show board

  for (int i = 1; i <= 10; i++){ // 10 moves
    board.update(); // move all players
    board.display(); // show the updated board
  }
}