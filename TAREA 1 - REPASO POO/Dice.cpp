/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#include <iostream>
#include "Dice.h"

Dice::Dice(int number_of_faces, int number)
{
    this->number_of_faces = number_of_faces;
    this->number = number;
}

Dice::~Dice()
{
}

int Dice::get_number_of_faces()
{
    return this->number_of_faces;
}

int Dice::get_number()
{
    return this->number;
}

void Dice::set_number_of_faces(int number_of_faces)
{
    this->number_of_faces = number_of_faces;
}

void Dice::set_number(int number)
{
    this->number = number;
}

int Dice::roll()
{
    this->number = rand() % this->number_of_faces + 1;
    return this->number;
}