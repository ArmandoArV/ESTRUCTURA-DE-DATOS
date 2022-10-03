/*
    Made by: Armando Arredondo Valle
    Date: 29/09/2022
*/
#include <iostream>
#include "stack.h"
#include "nodePtr.h"
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

void Stack::push(int data){
    NodePtr *newNode = new NodePtr(data);
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
        NodePtr *aux = top;
        top = top->getNext();
        delete aux;
    }
}

NodePtr *Stack::peek(){
    if(isEmpty()){
        cout << "The stack is empty" << endl;
        return NULL;
    }else{
        return top;
    }
}

