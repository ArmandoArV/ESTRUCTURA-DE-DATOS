#include <iostream>
#include <string>
using namespace std;

#pragma once
class Tile
{
    private:
        char type;
    public:
        Tile();
        Tile(char type);
        ~Tile();
        // Getters        
        char get_type();
        // Setters
        void set_type(char type);
};
