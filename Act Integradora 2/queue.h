/*
    Made by: Armando Arredondo Valle
    Date: 29/09/2022

*/

#pragma once
#include "nodePtrTwo.h"

class Queue {
    private:
        NodePtr *front;
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(int data);
        void dequeue();
        NodePtrTwo* peek();
        NodePtrTwo *getLast();
        int getSize();
};
