/*
 Created by Armando on 30/11/2022.
*/

#ifndef INTEGRADORA_CARRITO_LIST_H
#define INTEGRADORA_CARRITO_LIST_H
#include <iostream>
using namespace std;
#include "DoubleNodePointer.h"

class List {
private:
    DoubleNodePointer *head;
    void eraseData(Order);
public:
    List();
    ~List();

    bool insertOrder(Order*);
    // Getter
    DoubleNodePointer *getHead();
    // Setter
    void setHead(DoubleNodePointer*);
    // Methods
    void goThrough();
    int size();
    // Overload
    Order* operator[](int i);
    friend ostream& operator<<(ostream& os, const List& listPrint){
        if(listPrint.head == nullptr){
            os << "The list is empty" << endl;
        } else {
            DoubleNodePointer *temp = listPrint.head;
            while(temp != nullptr){
                os << temp->getData() << endl;
                temp = temp->getNext();
            }
        }
        return os;
    }
};


#endif //INTEGRADORA_CARRITO_LIST_H
