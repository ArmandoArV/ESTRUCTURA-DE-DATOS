/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/
#pragma once
using namespace std;

class Node{
    private:
        int data;
    public:
        Node(int data);
        Node();
        ~Node();
        int getData();
        void setData(int data);
};