/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "board.h"

Board::Board(int num_snakes, int num_ladders, int num_cells, int num_players)
{
    this->num_snakes = num_snakes;
    this->num_ladders = num_ladders;
    this->num_cells = num_cells;
    this->num_players = num_players;
}

Board::~Board()
{
    // Dtor
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

int Board::get_num_players()
{
    return this->num_players;
}

void Board::set_num_snakes(int num_snakes)
{
    this->num_snakes = num_snakes;
}

void Board::set_num_ladders(int num_ladders)
{
    this->num_ladders = num_ladders;
}

void Board::set_num_cells(int num_cells)
{
    this->num_cells = num_cells;
}

void Board::set_num_players(int num_players)
{
    this->num_players = num_players;
}

void Board::print_board()
{
    cout << "num_snakes: " << this->num_snakes << endl;
    cout << "num_ladders: " << this->num_ladders << endl;
    cout << "num_cells: " << this->num_cells << endl;
    cout << "num_players: " << this->num_players << endl;
}