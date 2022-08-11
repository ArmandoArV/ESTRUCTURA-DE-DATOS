/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "MyGame.h"
#include "validation.cpp"
using namespace std;

int MAX_TURNS = 5;
int N_OF_PLAYERS = 2;
int END_CASE = 0;

MyGame::MyGame(){
	maxTurn = 15;
	numberOfPlayers = 2;
	endCase = 5;
}

MyGame::MyGame(int maxTurn, int numberOfPlayers, int endCase){
	this->maxTurn = maxTurn;
	this->numberOfPlayers = numberOfPlayers;
	this->endCase = 5;
}

MyGame::~MyGame(){
	//dtor
}

void MyGame::start(){
	// here should require the number of players
	// and the number of turns
	cout << "Welcome to the game" << endl;
	cout << "Please enter the number of players: ";
	cin >> numberOfPlayers;
	cout << "Please enter the number of turns: ";
	cin >> maxTurn;
	Board board(NUMBER_OF_SNAKES, NUMBER_OF_LADDERS, NUMBER_OF_TILES);
	for (int i = 0; i < NUMBER_OF_TILES; ++i) {
    // here should order it into a matrix of 6 columns and 5 rows
    // and print it
    cout << board.check_Tile(i) << " ";
    // it will create 6 rows and 2 columns
    // and print it
    if (i % 6 == 5) {
      cout << endl;
    }

	}
}