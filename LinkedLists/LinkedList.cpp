#include "linkedList.h"
#include "nodePtr.h"
#include <iostream>
using namespace std;

linkedList::linkedList(){head = NULL;}

linkedList::~linkedList(){}

NodePtr* linkedList::getHead(){return head;}

void linkedList::setHead(NodePtr* head){this->head = head;}

void linkedList::eraseByKey(int Which){
    if(head == NULL){ //If the list is empty
        cout << "Empty list" << endl; //Print error message
        return; //Return
    } 
    else{ //If the list is not empty
        NodePtr* before = head, *aux = head; //Create two pointers to NodePtr and set them to head (before and aux) 
        while(aux != NULL && aux->getData() != Which){ //While the pointer is not null and the data is not the one we are looking for
            before = aux; //Move the before pointer to the current position
            aux = aux->getNext(); //Move the aux pointer to the next position
        }
        if(aux == NULL){ //If the pointer is null
            cout << "Not found" << endl; //Print error message
        }
        else if(aux == before){ //If the pointer is in the same position as the before pointer
            head = aux->getNext(); //Move the head pointer to the next position
            delete aux; //Delete the aux pointer
        }
        else{ //If the pointer is not in the same position as the before pointer
            before->setNext(aux->getNext()); //Move the before pointer to the next position
            delete aux; //Delete the aux pointer
        }
    }
}

void linkedList::insertInOrder(int data){
    NodePtr* newOne = new NodePtr(data);
    if (head == NULL){ //If the list is empty
        head = newOne; //If the list is empty, set the head pointer to the new node
    }
    else{ //If the list is not empty
        NodePtr* before = head, *aux = head; //Create two pointers to NodePtr and set them to head (before and aux) 
        while(aux != NULL && aux->getData() < data){ //While the pointer is not null and the data is not the one we are looking for
            before = aux; //Move the before pointer to the current position
            aux = aux->getNext(); //Move the aux pointer to the next position
        }
        if (aux == before){ //If the pointer is in the same position as the before pointer
            newOne->setNext(head); //Move the newOne pointer to the next position
            head = newOne; //Move the head pointer to the next position 
        }
        else if(aux==NULL){ //If the pointer is null
            before->setNext(newOne); //Move the before pointer to the next position 
        }
    }
}

void linkedList::recorrer(){
    if (head==NULL){
        cout << "Empty list" << endl;
    }
    else{
        NodePtr* aux = head;
        while(aux != NULL){
            cout << aux->getData() << "\n";
            aux = aux->getNext();
        }
    }
}

void linkedList::deleteLastValue(){
    if(head == NULL){ //If the list is empty
        cout << "Empty list" << endl; //Print error message
        return; //Return
    } 
    else{ //If the list is not empty
        NodePtr* before = head, *aux = head; //Create two pointers to NodePtr and set them to head (before and aux) 
        while(aux->getNext() != NULL){ //While the pointer is not null and the data is not the one we are looking for
            before = aux; //Move the before pointer to the current position
            aux = aux->getNext(); //Move the aux pointer to the next position
        }
        if(aux == before){ //If the pointer is in the same position as the before pointer
            head = NULL; //Move the head pointer to the next position
            delete aux; //Delete the aux pointer
        }
        else{ //If the pointer is not in the same position as the before pointer
            before->setNext(NULL); //Move the before pointer to the next position
            delete aux; //Delete the aux pointer
        }
    }
}

void linkedList::insertAtEnd(int data){
    NodePtr* newOne = new NodePtr(data);
    if (head == NULL){ //If the list is empty
        head = newOne; //If the list is empty, set the head pointer to the new node
    }
    else{ //If the list is not empty
        NodePtr* aux = head; //Create a pointer to NodePtr and set it to head (aux) 
        while(aux->getNext() != NULL){ //While the pointer is not null and the data is not the one we are looking for
            aux = aux->getNext(); //Move the aux pointer to the next position
        }
        aux->setNext(newOne); //Move the aux pointer to the next position
    }
}


void linkedList::insertAtStart(int data){
    NodePtr* newOne = new NodePtr(data);
    if (head == NULL){ //If the list is empty
        head = newOne; //If the list is empty, set the head pointer to the new node
    }
    else{ //If the list is not empty
        newOne->setNext(head); //Move the newOne pointer to the next position
        head = newOne; //Move the head pointer to the next position 
    }
}

void linkedList::deleteAtStart(){
    if(head == NULL){ //If the list is empty
        cout << "Empty list" << endl; //Print error message
        return; //Return
    } 
    else{ //If the list is not empty
        NodePtr* aux = head; //Create a pointer to NodePtr and set it to head (aux) 
        head = aux->getNext(); //Move the head pointer to the next position
        delete aux; //Delete the aux pointer
    }
}

