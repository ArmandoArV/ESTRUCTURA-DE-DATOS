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

#pragma once
const int NUMBER_OF_TILES = 30;
const int NUMBER_OF_SNAKES = 3;
const int NUMBER_OF_LADDERS = 3;

class Board {
private:
  Tile Tile[NUMBER_OF_TILES];
  Dice dice();
  int num_snakes;
  int num_ladders;
  int num_cells;

public:
  Board();
  Board(int num_snakes, int num_ladders, int num_cells);
  ~Board();
  // Getters
  int get_num_snakes();
  int get_num_ladders();
  int get_num_cells();
  // Setters
  void set_num_snakes(int num_snakes);
  void set_num_ladders(int num_ladders);
  void set_num_cells(int num_cells);
  // Methods
  void print_board();
  void check_Tile();
};
