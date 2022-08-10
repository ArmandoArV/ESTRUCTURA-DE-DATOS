/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include "Board.cpp"
#include "Dice.cpp"
#include "Tile.cpp"
#include <iostream>
#include <string>

using namespace std;


Board board(NUMBER_OF_SNAKES, NUMBER_OF_LADDERS, NUMBER_OF_TILES);

int main(){
  char option;
  //ContinueOrExit(option);
  board.print_board();
  return 0;
}
