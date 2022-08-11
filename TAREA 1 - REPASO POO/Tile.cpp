/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "Tile.h"

Tile::Tile(){
    type= 'N';
}

Tile::Tile(char type_){
		type = type_;
}

Tile::~Tile(){
}

char Tile::get_type(){
    return type;
}

void Tile::set_type(char value){
    type= value;
}

