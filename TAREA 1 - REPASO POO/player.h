/*
    Made by: 
        - Antonio Noguerón Bárcenas
        - Armando Arredondo Valle
*/

#pragma once

class Player{
    private:
        int playerNumber;
        int position;
    public:
        Player();
        Player(int playerNumber,int position);
        ~Player();
        // Getters
        int getPlayerNumber();
        int getPosition();
        // Setters
        void setPlayerNumber(int playerNumber);
        void setPosition(int position);
};
