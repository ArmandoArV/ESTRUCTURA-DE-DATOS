/*
    Made by: Armando Arredondo Valle
    Date: 29/09/2022

*/

#pragma once
#include "nodePtrTwo.h"

class Stack{
    private:
        NodePtrTwo *top;
    public:
        Stack();
        ~Stack();
        void push(int);
        void pop();
        NodePtrTwo *peek();
        bool isEmpty();
};