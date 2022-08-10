/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "Player.h"

Player::Player(){
	playerNumber = 0;
	position = 1;
}
Player::Player(int playerNum, int pos){
	playerNumber = playerNum;
	position = pos;
}

Player::~Player(){
}

int Player::getPlayerNumber(){
	return playerNumber;
}

int Player::getPosition(){
	return position;
}

void Player::setPlayerNumber(int playerNumber_){
	playerNumber = playerNumber_;
}

void Player::setPosition(int position_){
	position = position_;
}
