/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "Tile.h"

Tile::Tile(){
    id = 0;
    status = 'N';
}

Tile::Tile(int id_, char status_){
    id = id_;
		status = status_;
}

Tile::~Tile(){
}

int Tile::get_id(){
    return id;
}

char Tile::get_status(){
    return status;
}

void Tile::set_id(int id_){
    id = id_;
}

void Tile::set_status(char value){
    status= value;
}

