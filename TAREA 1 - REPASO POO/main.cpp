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

    return 0;
}