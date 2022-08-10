/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include <string>
using namespace std;

#pragma once

class Box
{
    private:
        int position;
        int value;
        char is_snake,is_ladder;
    public:
        Box();
        Box(int position, int value, char is_snake, char is_ladder);
        ~Box();
        // Getters
        int get_position();
        int get_value();
        char get_is_snake();
        char get_is_ladder();
        // Setters
        void set_position(int position);
        void set_value(int value);
        void set_is_snake(char is_snake);
        void set_is_ladder(char is_ladder);
        void check_box();
};
