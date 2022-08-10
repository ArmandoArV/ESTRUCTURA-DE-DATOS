#include "MyGame.h"
#include "Board.cpp"
#include <iostream>
using namespace std;

MyGame::MyGame(int MaxTurns, int numberOfPlayers, char option) {
    this->MaxTurns = MaxTurns;
    this->numberOfPlayers = numberOfPlayers;
    this->option = ' ';
}

MyGame::~MyGame() {
    //dtor
}

int MyGame::getMaxTurns() {return MaxTurns;}

int MyGame::getNumberOfPlayers() {return numberOfPlayers;}

char MyGame::getOption() {return option;}

void MyGame::setMaxTurns(int MaxTurns) {this->MaxTurns = MaxTurns;}

void MyGame::setNumberOfPlayers(int numberOfPlayers) {this->numberOfPlayers = numberOfPlayers;}

void MyGame::setOption(char option) {this->option = option;}

void MyGame::startGame() {
    Board board;
    cout << "Welcome to the game" << endl;
    cout << "Max turns: " << MaxTurns << endl;
    cout << "Number of players: " << numberOfPlayers << endl;
    cin >> MaxTurns;
    cin >> numberOfPlayers;
    // here should print the board
    board.print_board();
}
