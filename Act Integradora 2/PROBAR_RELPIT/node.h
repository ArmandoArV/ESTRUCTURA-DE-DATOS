/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/
#pragma once
using namespace std;
#include "binnacle.h"
class Node{
    private:
        Binnacle data;
    public:
        Node(Binnacle data);
        Node();
        ~Node();
        Binnacle getData();
        void setData(Binnacle data);
};