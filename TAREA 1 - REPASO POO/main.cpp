/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include <string>
#include "Board.h"
#include "Dice.h"

using namespace std;

const int NUMBER_OF_SNAKES = 3;
const int NUMBER_OF_LADDERS = 3;

Board board(NUMBER_OF_SNAKES,NUMBER_OF_LADDERS,NUMBER_OF_TILES);

void ContinueOrExit(char &option){
    cout << "Press C to continue" << endl;
    cout << "Press E to exit" << endl;
    cin >> option;
    if(option != 'C' && option != 'c' && option != 'E' && option != 'e'){
        cout << "Invalid option" << endl;
        ContinueOrExit(option);
    }
    if(option == 'E' || option == 'e'){
        cout << "Thanks for playing!!!" << endl;
        exit(0);
    }
}

int main()
{
    char option;
    ContinueOrExit(option);
    board.print_board();
    return 0;
}
