/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/
#pragma once
#include "nodePtrTwo.h"
#include "binnacle.h"
#include <iostream>
using namespace std;

class linkedListTwo: public NodePtrTwo{
    private:
        NodePtrTwo* head;
    public:
        linkedListTwo();
        ~linkedListTwo();
        NodePtrTwo* getHead();
        void setHead(NodePtrTwo*);
        void recorrer();
        void appendInOrder(Binnacle);
        void eraseByData(string);
        void searchByData(string,string);
        void viewLast();
        void viewFirst();
        bool isEmpty();
        ostream& operator<<(std::ostream &o);
};