/*
    Made by: Armando Arredondo Valle
    Date: 29/09/2022
*/

#include "queue.h"
#include <iostream>
using namespace std;

Queue::Queue(){
    front = NULL;
}

Queue::~Queue(){}

bool Queue::isEmpty(){
    if(front == NULL){
        return true;
    }else{
        return false;
    }
}

void Queue::enqueue(int data){
    NodePtr *newNode = new NodePtr(data);
    if(isEmpty()){
        front = newNode;
    }else{
        NodePtr *aux = front;
        while(aux->getNext() != NULL){
            aux = aux->getNext();
        }
        aux->setNext(newNode);
    }
}

void Queue::dequeue(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
    }else{
        NodePtr *aux = front;
        front = front->getNext();
        delete aux;
    }
}

NodePtr *Queue::peek(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
        return NULL;
    }else{
        return front;
    }
}

NodePtr *Queue::getLast(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
        return NULL;
    }else{
        NodePtr *aux = front;
        while(aux->getNext() != NULL){
            aux = aux->getNext();
        }
        return aux;
    }
}

int Queue::getSize(){
    if(isEmpty()){
        cout << "The queue is empty" << endl;
        return 0;
    }else{
        int size = 0;
        NodePtr *aux = front;
        while(aux != NULL){
            size++;
            aux = aux->getNext();
        }
        return size;
    }
}
