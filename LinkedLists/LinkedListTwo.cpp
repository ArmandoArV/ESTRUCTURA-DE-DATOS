#include "linkedListTwo.h"
#include "nodePtrTwo.h"
#include <iostream>

using namespace std;

linkedListTwo::linkedListTwo(){this->head = NULL;}

linkedListTwo::~linkedListTwo(){}

NodePtrTwo* linkedListTwo::getHead(){return this->head;}

void linkedListTwo::setHead(NodePtrTwo *head){this->head = head;}




void linkedListTwo::recorrer(){    //Imprime todos los valores de la lista
            if(head == NULL){    //Si la lista está vacia
                cout << "La lista está vacia" << endl;
            } else {    //Si la lista no está vacia
                NodePtrTwo *aux = head;    //Apuntador auxiliar para sacar datos
                while(aux != NULL){    //Mientras el aux no llegue al final
                    cout << "Dato: " << aux->getData();
                    if(aux->getBefore() != NULL){
                        cout << "\t| Dato anterior: " << aux->getBefore()->getData();
                    } else {
                        cout << "\t| Dato anterior: No hay";
                    }
                    if(aux->getNext() != NULL){
                        cout << "\t| Dato siguiente: " << aux->getNext()->getData() << endl;
                    } else {
                        cout << "\t| Dato siguiente: No hay\n";
                    }
                        //Imprime el dato de la posición del auxiliar actual
                    aux = aux->getNext();    //Pasa al siguiente
                }
            }
        }

void linkedListTwo::insertInOrder(int data){
    NodePtrTwo* newOne = new NodePtrTwo(data);
    if (head == NULL){ //If the list is empty
        head = newOne; //If the list is empty, set the head pointer to the new node
    }
    else{ //If the list is not empty
        NodePtrTwo* before = head, *aux = head; //Create two pointers to NodePtr and set them to head (before and aux) 
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

