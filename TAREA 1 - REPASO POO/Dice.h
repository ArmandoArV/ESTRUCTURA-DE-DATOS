/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

const int NUMBER_OF_FACES = 6;
#pragma once

class Dice{
    private:
        int number_of_faces;
        int number;
    public:
        Dice();
        Dice(int number_of_faces,int number);
        ~Dice();
        // Getters
        int get_number_of_faces();
        int get_number();
        // Setters
        void set_number_of_faces(int number_of_faces);
        void set_number(int number);
        // Methods
        int roll();

};
