/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "player.h"


Player::Player(int position, int points, int num_dice){
    this->position = position;
    this->points = points;
    this->num_dice = num_dice;
}

Player::~Player(){
    //dtor
}

int Player::get_position(){
    return this->position;
}

int Player::get_points(){
    return this->points;
}

int Player::get_num_dice(){
    return this->num_dice;
}

Dice *Player::get_dice(){
    return this->dice;
}

// Setters
void Player::set_position(int position){
    this->position = position;
}

void Player::set_points(int points){
    this->points = points;
}

void Player::set_num_dice(int num_dice){
    this->num_dice = num_dice;
}

void Player::set_dice(Dice *dice){
    this->dice = dice;
}

void Player::move_player(){
    this->position += this->dice->roll();
}

void Player::check_dice(){
    if(this->dice->get_number_of_faces() == 0){
        std::cout << "The dice has no faces" << std::endl;
    }
}

void Player::check_box(){
    if(this->position > 100){
        this->position = this->position - 100;
        this->points += 100;
    }
}

void Player::check_position(){
    if(this->position > 100){
        this->position = this->position - 100;
    }
}   

void Player::check_num_dice(){
    if(this->num_dice == 0){
        std::cout << "The player has no dice" << std::endl;
    }
}