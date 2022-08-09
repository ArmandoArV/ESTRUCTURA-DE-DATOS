/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/


using namespace std;
#include <string>
#include <vector>
#include "box.h"
#include "dice.h"

const int NUMBER_OF_CELLS = 30;

class Board{
    private:
        Box box [NUMBER_OF_CELLS];
        Dice dice;
        int num_snakes;
        int num_ladders;
        int num_cells;
        int current_position;
    public:
        Board();
        Board(int num_snakes, int num_ladders, int num_cells);
        ~Board();
        // Getters
        int get_num_snakes();
        int get_num_ladders();
        int get_num_cells();
        int get_current_position();
        // Setters
        void set_num_snakes(int num_snakes);
        void set_num_ladders(int num_ladders);
        void set_num_cells(int num_cells);
        void set_current_position(int current_position);
        // Methods
        void print_board();
        void check_box();
};