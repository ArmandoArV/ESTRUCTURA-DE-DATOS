/*
    Date: 08/10/2022
    Made by: Armando Arredondo Valle
*/
#include "linkedListTwo.h"
#include "nodePtrTwo.h"
#include "binnacle.h"
#include "queue.h"
#include <iostream>

using namespace std;

linkedListTwo::linkedListTwo(){this->head = NULL;}

linkedListTwo::~linkedListTwo(){}

NodePtrTwo* linkedListTwo::getHead(){return this->head;}

void linkedListTwo::setHead(NodePtrTwo *head){this->head = head;}

bool linkedListTwo::isEmpty(){if (head == NULL){return true;}else{return false;}}

void linkedListTwo::appendInOrder(Binnacle data) { // Complejidad O👎
    NodePtrTwo* newNode = new NodePtrTwo(data); //Creamos el nuevo nodo
    if(isEmpty()){ // si está vacía entonces el nuevo nodo es la cabeza de la lista
        head = newNode;
    } else {
        NodePtrTwo* previous = head, *aux = head; //Creamos nuestros apuntadores auxiliares
        while( aux != nullptr && aux->getData() <= data ){ //Nos movemos con los apuntadores hasta encontrar el lugar donde entra el nodo
            previous = aux;
            aux = aux->getNext();
        }
        if (aux == nullptr){ // si estamos al final
            previous->setNext(newNode);
            newNode->setBefore(previous);
        } else if (aux == previous){ // si va en el primer elemento
            newNode->setNext(head);
            head->setBefore(newNode);
            head = newNode;
        } else { // en cualquier otro caso
            previous->setNext(newNode);
            newNode->setNext(aux);
            newNode->setBefore(previous);
            aux->setBefore(newNode);
        }
    }
} // Complejidad O(N)

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
            cout << "\n=============================================================================================================================================\n";
            cout << "||                                                      Erase                                                                                ||" << "\n";
            cout << "=============================================================================================================================================\n";
            cout << "\n =========================================== The IP: " << data << " has been deleted =======================================\n";
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
} // Complejidad O(n)



void linkedListTwo::recorrer() {
    NodePtrTwo* aux = head;
    while(aux != NULL){
        cout << "| IP: | " << aux->getData().getIP() << " | Port: | " << aux->getData().getPort() << " | Month: | " << aux->getData().getDate().getMonthInt() << " | Day: | " << aux->getData().getDate().getDay() << " | Hour: | " << aux->getData().getDate().getHour() << " | Minutes: | " << aux->getData().getDate().getMinute() << " | Seconds: | "  << aux->getData().getDate().getSecond()<< " | Action: | " << aux->getData().getReason() << "\n";
        cout << "--------------------------------------------------------------------------------------------------------------------------------" << "\n";
        aux = aux->getNext();
    }
} // Complejidad O(n)

void linkedListTwo::searchByData(string data,string data2){
    linkedListTwo newList;
    if(isEmpty()){
        cout << "The list is empty\n";
    }
    else
    {
        NodePtrTwo *aux = head, *before = head;
        while (aux != NULL){
            if(aux->getData().getIP() >= data && aux->getData().getIP() <= data2){
                newList.appendInOrder(aux->getData());
                
            }
            before = aux;
            aux = aux->getNext();
        }
    }
    cout << "\n=============================================================================================================================================\n";
    cout << "||                                                  Check between                                                                            ||" << "\n";
    cout << "=============================================================================================================================================\n";
    cout << "\n========================================== The IPs between " << data << " and " << data2 << " are: =======================================\n";
    return newList.recorrer();
} // Complejidad O(n)


void linkedListTwo::viewLast(){
    if (head == NULL){
    cout << "NULL" << endl;
    }
    else{
        NodePtrTwo *antes = head, *aux=head;
        while(aux != NULL){
        antes = aux;
        aux = aux->getNext();
        }
    if (aux == NULL){
        cout << "The last IP is: " << antes->getData().getIP() << endl;
        }
    }
}//Complejidad: O(N)

void linkedListTwo::viewFirst(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
    }else{
        cout << "The first element is: " << head->getData().getIP() << "\n";
    }
} // Complejidad O(1)