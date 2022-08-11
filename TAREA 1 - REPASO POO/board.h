/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

using namespace std;
#include "Dice.h"
#include "Tile.h"
#include <string>
#include <vector>

const int NUMBER_OF_TILES = 30;
const int NUMBER_OF_SNAKES = 3;
const int NUMBER_OF_LADDERS = 3;

#pragma once

class Board {
private:
  Tile Tiles[NUMBER_OF_TILES];
  Dice dice();
  int num_snakes;
  int num_ladders;
  int num_tiles;
  void create_board();
	int getRandomsToCreateBoard();

public:
  Board();
  Board(int num_snakes, int num_ladders, int num_tiles);
  ~Board();
  // Getters
  int get_num_snakes();
  int get_num_ladders();
  int get_num_tiles();
  // Setters
  void set_num_snakes(int num_snakes);
  void set_num_ladders(int num_ladders);
  void set_num_tiles(int num_tiles);
  // Methods
  char check_Tile(int tileNum);
};
