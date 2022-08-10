/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "Dice.h"
Dice::Dice(){
    number_of_faces = 6;
    number = 1;
}

Dice::Dice(int face_num, int num)
{
    number_of_faces = face_num;
    number = num;
}

Dice::~Dice()
{
}

int Dice::get_number_of_faces()
{
    return number_of_faces;
}

int Dice::get_number()
{
    return number;
}

void Dice::set_number_of_faces(int number_of_faces_)
{
    number_of_faces = number_of_faces_;
}

void Dice::set_number(int num)
{
    number = num;
}

int Dice::roll()
{
    number = rand() % number_of_faces + 1;
    return number;
}
