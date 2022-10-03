/*
    Made by: Armando Arredondo Valle
    Date: 29/09/2022
*/
#include <iostream>
#include "stack.h"
#include "nodePtrTwo.h"
using namespace std;

Stack::Stack(){
    top = NULL;
}

Stack::~Stack(){}

bool Stack::isEmpty(){
    if(top == NULL){
        return true;
    }else{
        return false;
    }
}

void Stack::push(Binnacle data){
    NodePtrTwo *newNode = new NodePtrTwo(data);
    if(isEmpty()){
        top = newNode;
    }else{
        newNode->setNext(top);
        top = newNode;
    }
}

void Stack::pop(){
    if(isEmpty()){
        cout << "The stack is empty" << endl;
    }else{
        NodePtrTwo *aux = top;
        top = top->getNext();
        delete aux;
    }
}

NodePtrTwo *Stack::peek(){
    if(isEmpty()){
        cout << "The stack is empty" << endl;
        return NULL;
    }else{
        return top;
    }
}

