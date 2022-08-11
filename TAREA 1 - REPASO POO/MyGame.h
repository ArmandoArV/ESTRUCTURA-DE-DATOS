/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/
#include "Board.h"
#include "Dice.h"
#include "Tile.h"
using namespace std;

#pragma once
class MyGame {
	private:
		int maxTurn;
		int numberOfPlayers;
		int endCase;
		//Aqui se puede poner el continue or exit
		// y podemos empezar la logica de correr el
		// desde MyGame 
	public:
		MyGame();
		MyGame(int, int,int);
		~MyGame();
		void start();
};
