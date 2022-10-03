/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/
#include "linkedListTwo.h"
#include "nodePtrTwo.h"
#include "binnacle.h"
#include <iostream>

using namespace std;

linkedListTwo::linkedListTwo(){this->head = NULL;}

linkedListTwo::~linkedListTwo(){}

NodePtrTwo* linkedListTwo::getHead(){return this->head;}

void linkedListTwo::setHead(NodePtrTwo *head){this->head = head;}

bool linkedListTwo::isEmpty(){return this->head == NULL;}


void linkedListTwo::recorrer(){
    NodePtrTwo* aux = this->head;
    while (aux != NULL){
        cout << aux->getData() << endl;
        aux = aux->getNext();
    }
}