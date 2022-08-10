/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "Board.h"
#include "Dice.h"
#include "Tile.h"
Board::Board(int num_snakes, int num_ladders, int num_cells)
{
    this->num_snakes = num_snakes;
    this->num_ladders = num_ladders;
    this->num_cells = num_cells;
}

Board::Board()
{
    this->num_snakes = 0;
    this->num_ladders = 0;
    this->num_cells = 0;
}

Board::~Board()
{
    //dtor
}

int Board::get_num_snakes()
{
    return this->num_snakes;
}

int Board::get_num_ladders()
{
    return this->num_ladders;
}

int Board::get_num_cells()
{
    return this->num_cells;
}

int Board::get_current_position()
{
    return this->current_position;
}

void Board::set_num_snakes(int num_snakes)
{
    this->num_snakes = num_snakes;
}

void Board::set_num_ladders(int num_ladders){
    this->num_ladders = num_ladders;
}

void Board::set_num_cells(int num_cells){
    this->num_cells = num_cells;
}

void Board::set_current_position(int current_position){
    this->current_position = current_position;
}

void Board::print_board(){
    // here should be the print of the board if it isn't a snake or a ladder letter N will appear else the letter of the snake or the ladder
    std::cout << "Board: " << std::endl;
    for(int i = 0; i < this->num_cells; i++){
        if(i == this->current_position){
            cout << "N ";
        }
        else{
            
            cout << "O ";
        }
    }
    

}
