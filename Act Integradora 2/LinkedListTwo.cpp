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

bool linkedListTwo::isEmpty(){if (head == NULL){return true;}else{return false;}}

void linkedListTwo::appendInOrder(Binnacle data) {
    NodePtrTwo* newOne = new NodePtrTwo(data);
    if (head == NULL){ //If the list is empty
        head = newOne; //If the list is empty, set the head pointer to the new node
    }
    else{ //If the list is not empty
        NodePtrTwo* before = head, *aux = head; //Create two pointers to NodePtr and set them to head (before and aux) 
        while (aux != NULL && aux->getData().getDate().getMonthInt() <= data.getDate().getMonthInt()){ //While aux is not null and the month of the data in the node is less than the month of the data in the new node
            before = aux; //Set before to aux
            aux = aux->getNext(); //Set aux to the next node
        }
                if (aux == before){ //If the pointer is in the same position as the before pointer
            newOne->setNext(head); //Move the newOne pointer to the next position
            head = newOne; //Move the head pointer to the next position 
        }
        else if(aux==NULL){ //If the pointer is null
            before->setNext(newOne); //Move the before pointer to the next position 
        }
        else{
            before->setNext(newOne); //Move the before pointer to the next position
            newOne->setNext(aux); //Move the newOne pointer to the next position
        }
    }
}


void linkedListTwo::printThrough() {
    NodePtrTwo* aux = head;
    while(aux != NULL){
        cout << "| IP: | " << aux->getData().getIP() << " | Port: | " << aux->getData().getPort() << " | Action: | " << aux->getData().getReason() << "| Month: | " << aux->getData().getDate().getMonthInt() << " | Day: | " << aux->getData().getDay()  << "\n";
        aux = aux->getNext();
    }
}