/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "box.h"

Box::Box(int position, int value, char is_snake, char is_ladder){
    this->position = position;
    this->value = value;
    this->is_snake = is_snake;
    this->is_ladder = is_ladder;
}

Box::~Box(){
}

int Box::get_position(){
    return this->position;
}

int Box::get_value(){
    return this->value;
}

char Box::get_is_snake(){
    return this->is_snake;
}

char Box::get_is_ladder(){
    return this->is_ladder;
}

void Box::set_position(int position){
    this->position = position;
}

void Box::set_value(int value){
    this->value = value;
}

void Box::set_is_snake(char is_snake){
    this->is_snake = is_snake;
}

void Box::set_is_ladder(char is_ladder){
    this->is_ladder = is_ladder;
}

void Box::check_box(){
    if(this->is_snake == 'S'){
        this->value = -this->value;
    }
    if(this->is_ladder == 'L'){
        this->value = -this->value;
    }
}
