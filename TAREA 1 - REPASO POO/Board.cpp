/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

Board::Board(){
	num_snakes = 3;
	num_ladders = 3;
	num_tiles = 30;
	create_board();
}

Board::Board(int num_snakes_, int num_ladders_, int num_tiles_) {
  num_snakes = num_snakes_;
  num_ladders = num_ladders_;
  num_tiles = num_tiles_;
	create_board();
}

Board::~Board() {
}

int Board::get_num_snakes() {
	return num_snakes; 
}

int Board::get_num_ladders() {
	return num_ladders;
}

int Board::get_num_tiles() {
	return num_tiles;
}

void Board::set_num_snakes(int num_snakes_) {
	num_snakes = num_snakes_;
}

void Board::set_num_ladders(int num_ladders_) {
  num_ladders = num_ladders_;
}

void Board::set_num_tiles(int num_tiles_) { 
	num_tiles = num_tiles_; 
}

void Board::create_board(){
	srand(time(0));
	int tempNum = 0;
	while (tempNum < num_ladders) {
		int r = getRandomsToCreateBoard();
		if (Tiles[r].get_type() == 'N') {
			Tiles[r].set_type('L');
			tempNum++;
		}
	}
	tempNum = 0;
	while (tempNum < num_snakes) {
		int r = getRandomsToCreateBoard();
		if (Tiles[r].get_type() == 'N') {
			Tiles[r].set_type('S');
			tempNum++;
		}
	}
}

int Board::getRandomsToCreateBoard(){
	return rand() % (num_tiles-2) + 1;
}

char Board::check_Tile(int tileNum){
	return Tiles[tileNum].get_type();
}