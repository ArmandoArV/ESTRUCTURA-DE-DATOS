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
        while (aux != NULL && aux->getData().getDate().getMonthInt() <= data.getDate().getMonthInt() && aux->getData().getDate().getDay() <= data.getDate().getDay()){ //While aux is not null and the month of the data in the node is less than the month of the data in the new node
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

void linkedListTwo::eraseByData(string data){
    if(isEmpty()){
        cout << "The list is empty\n";
    }
    else {
        NodePtrTwo *before = head, *aux = head;
        while (aux != NULL && aux->getData().getIP() != data){
            before = aux;
            aux = aux->getNext();
        }
        if (aux==NULL){
            cout << " =========================================== The IP: " << data << " has been deleted =======================================\n";
        }
        else if (aux == before){
            head = aux->getNext();
            if (head != NULL){
                head -> setBefore(NULL);
            }
            delete aux;
        }
        else {
            before -> setNext(aux -> getNext());
            if (before -> getNext() != NULL){
                aux -> getNext() -> setBefore(before);
            }
            delete aux;
            this -> eraseByData(data);
        }
    }
}



void linkedListTwo::printThrough() {
    NodePtrTwo* aux = head;
    while(aux != NULL){

        cout << "| IP: | " << aux->getData().getIP() << " | Port: | " << aux->getData().getPort() << " | Month: | " << aux->getData().getDate().getMonthInt() << " | Day: | " << aux->getData().getDate().getDay() << " | Hour: | " << aux->getData().getDate().getHour() << " | Minutes: | " << aux->getData().getDate().getMinute() << " | Seconds: | "  << aux->getData().getDate().getSecond()<< " | Action: | " << aux->getData().getReason() << "\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------" << "\n";
        aux = aux->getNext();
    }
}

void linkedListTwo::searchByData(string data,string data2){
    linkedListTwo newList;
    if(isEmpty()){
        cout << "The list is empty\n";
    }
    else
    {
        NodePtrTwo *aux = head, *before = head;
        while (aux != NULL){
            if(aux->getData().getIP() >= data && aux->getData().getIP() >= data2){
                newList.appendInOrder(aux->getData());
            }
            before = aux;
            aux = aux->getNext();
        }
    }
    cout << "========================================== The IPs between " << data << " and " << data2 << " are: =======================================\n";
    return newList.printThrough();
}
