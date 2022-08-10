/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include "Board.h"
#include <iostream>

Board::Board(int num_snakes, int num_ladders, int num_cells) {
  this->num_snakes = num_snakes;
  this->num_ladders = num_ladders;
  this->num_cells = num_cells;
}

Board::~Board() {
  // dtor
}

int Board::get_num_snakes() { return this->num_snakes; }

int Board::get_num_ladders() { return this->num_ladders; }

int Board::get_num_cells() { return this->num_cells; }

void Board::set_num_snakes(int num_snakes) { this->num_snakes = num_snakes; }

void Board::set_num_ladders(int num_ladders) {
  this->num_ladders = num_ladders;
}

void Board::set_num_cells(int num_cells) { this->num_cells = num_cells; }

void Board::print_board() {
  for (int i = 0; i < NUMBER_OF_TILES; i++) {
    // it will add a ladder or a snake in a random position in the board (not in
    // the first or last position)
    // the number of snakes and ladders will be determined by the variables in the constructor
    if (i != 0 && i != NUMBER_OF_TILES - 1) {
      if (i % 2 == 0) {
        if (this->num_snakes > 0) {
          this->Tile[i].set_status('S');
          this->num_snakes--;
        }
      } else {
        if (this->num_ladders > 0) {
          this->Tile[i].set_status('L');
          this->num_ladders--;
        }
      }
    }
    // it will print the board 6x5 (6 rows and 5 columns)
    if (i % 6 == 0) {
      cout << endl;
    }
    // there can't be more than one snake or ladder in a row if there is more than one snake or ladder in the row change it to letter N
    if (this->Tile[i].get_status() == 'S' && this->Tile[i + 1].get_status() == 'S') {
      this->Tile[i].set_status('N');
    }
    if (this->Tile[i].get_status() == 'L' && this->Tile[i + 1].get_status() == 'L') {
      this->Tile[i].set_status('N');
    }
    // print the board

    cout << this->Tile[i].get_status();
  }
}