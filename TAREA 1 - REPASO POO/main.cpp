/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include <string>
#include "board.h"
#include "dice.h"

using namespace std;

Board board;

int numberOfsnakes = 3;
int numberOfladders = 3;
int numberOfCells = 30;

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

void requireNumberOfPlayers(int &num_players){
    cout << "Please enter the number of players: " << endl;
    cin >> num_players;
    board.set_num_players(num_players);
}


int main()
{
    char option;
    ContinueOrExit(option);
    board.set_num_snakes(numberOfsnakes);
    board.set_num_ladders(numberOfladders);
    board.set_num_cells(numberOfCells);
    board.print_board();

    return 0;
}