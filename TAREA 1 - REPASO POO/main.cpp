/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include <string>
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Box.h"

using namespace std;

Board board;

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
    Board board1 = Board(5,5,30);
    Dice dice = Dice(6);


    return 0;
}