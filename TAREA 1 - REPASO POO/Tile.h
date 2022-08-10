#include <iostream>
#include <string>
using namespace std;

#pragma once
class Tile
{
    private:
        int id;
        char status;
    public:
        Tile();
        Tile(int id, char status);
        ~Tile();
        // Getters
        int get_id();
        char get_status();
        // Setters
        void set_id(int id);
        void set_status(char status);
};
