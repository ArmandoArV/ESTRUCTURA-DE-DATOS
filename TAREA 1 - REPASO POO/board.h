/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/


using namespace std;
#include <string>
#include <vector>

class Board{
    private:
        int num_snakes;
        int num_ladders;
        int num_cells;
        int num_players;
        int num_dice;
        int num_turns;
        int prison_cell;
        int start_cell;
        int end_cell;
        int dice_roll;
        vector<int> ladder_cells;
        vector<int> snake_cells;
        vector<int> snake_length;
        vector<int> snake_direction;
        vector<int> ladder_length;
        vector<int> ladder_direction;
    public:
        
};