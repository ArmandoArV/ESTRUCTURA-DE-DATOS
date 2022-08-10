/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#pragma once
#include "Dice.h"
#include "Box.h"

class Player{
    private:
        int position;
        int points;
        int num_dice;

        Dice *dice;
    public:
        Player();
        Player(int position, int points, int num_dice);
        ~Player();
        // Getters
        int get_position();
        int get_points();
        int get_num_dice();
        Dice *get_dice();
        // Setters
        void set_position(int position);
        void set_points(int points);
        void set_num_dice(int num_dice);

        void set_dice(Dice *dice);
        // Methods
        void move_player();
        void check_dice();
        void check_box();
        void check_position();
        void check_num_dice();
};