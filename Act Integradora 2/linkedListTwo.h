/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/
#pragma once
#include "nodePtrTwo.h"
#include "binnacle.h"
#include <iostream>
using namespace std;

class linkedListTwo{
    private:
        NodePtrTwo* head;
    public:
        linkedListTwo();
        ~linkedListTwo();
        NodePtrTwo* getHead();
        void setHead(NodePtrTwo*);
        void recorrer();
        void insertInOrder(Binnacle);
        void eraseByData(Binnacle);
        bool isEmpty();
};