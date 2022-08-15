/*
    Made by:
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include "Board.cpp"
#include "Dice.cpp"
#include "Tile.cpp"
#include "MyGame.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

//Debe ir en mygame junto con el dado
MyGame game(MAX_TURNS, N_OF_PLAYERS, END_CASE);
/*
  En Mygame deben crearse los jugadores. 
  Estaba pensando si hacerlo "dinamico" preparando todo para la posibilidad de que fuera un numero distinto a 2 de jugadores,
  pero no creo que sea necesario esmerarse tanto para una tarea como esta XD
  podemos dejarlo en 2 y declarar cada jugador a mano en vez de un array, pero como lo consideres mejor,
  si lo ves sencillo y lo quieres hacer, hazlo, sino, ma;ana no tengo la n~ xD 
  dependiendo las ganas que tenga de hacer algo veo si lo implemento o no
*/
//Puede ir en mygame o en validation y llamarlo en Mygame
void ContinueOrExit(char &option) {
  cout << "Press C to continue" << endl;
  cout << "Press E to exit" << endl;
  cin >> option;
  if (option != 'C' && option != 'c' && option != 'E' && option != 'e') {
    cout << "Invalid option" << endl;
    ContinueOrExit(option);
  }
  if (option == 'E' || option == 'e') {
    cout << "Thanks for playing!!!" << endl;
    exit(0);
  }
}

int main() {
	char option;
  game.start();
  ContinueOrExit(option);
  return 0;
}

