/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include "Dice.h"
#include <iostream>
#include <string>
#include "Tile.h"
#include "Board.h"
#include "Player.h"


using namespace std;


Board board = Board(NUMBER_OF_SNAKES, NUMBER_OF_LADDERS, NUMBER_OF_TILES);

void ContinueOrExit(char &option) {
  cout << "Press C to continue" << endl;
  cout << "Press E to exit" << endl;
  cin >> option;
  if (option != 'C' && option != 'c' && option != 'E' && option != 'e') {
    cout << "Invalid option" << endl;
    ContinueOrExit(option);
  }
  if (option == 'E' || option == 'e') {
    cout << "Thanks for playing!!!" << endl;
    exit(0);
  }
}

int main() {
  char option;
  ContinueOrExit(option);
  return 0;
}
