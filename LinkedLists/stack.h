/*
    Made by: Armando Arredondo Valle
    Date: 29/09/2022

*/

#pragma once
#include "nodePtr.h"

class Stack{
    private:
        NodePtr *top;
    public:
        Stack();
        ~Stack();
        void push(int);
        void pop();
        NodePtr *peek();
        bool isEmpty();
};