/*
    Made by: Armando Arredondo Valle
    Date: 29/09/2022

*/

#pragma once
#include "nodePtrTwo.h"
#include "binnacle.h"
class Queue {
    private:
        NodePtrTwo *front;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(Binnacle data);
        void dequeue();
        NodePtrTwo* peek();
        NodePtrTwo *getLast();
        int getSize();
};
