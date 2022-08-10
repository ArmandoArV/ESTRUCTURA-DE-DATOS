#include <iostream>
#include <string>
using namespace std;
#pragma once


class Tile
{
    private:
        int id;
        char status;
        char value;
        int number;
    public:
        Tile();
        Tile(int id, char status);
        ~Tile();
        // Getters
        int get_id();
        char get_status();
        int get_number();
        // Setters
        void set_id(int id);
        void set_status(char status);
        void set_number(int number);
};
