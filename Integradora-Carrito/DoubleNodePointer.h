/*
 Created by Armando on 30/11/2022.
*/

#ifndef INTEGRADORA_CARRITO_DOUBLENODEPOINTER_H
#define INTEGRADORA_CARRITO_DOUBLENODEPOINTER_H

#include "Order.h"

class DoubleNodePointer {
    private:
        Order* data;
        DoubleNodePointer* next, *prev;
    public:
        DoubleNodePointer();
        DoubleNodePointer(Order*);
        ~DoubleNodePointer();
        // Getters
        DoubleNodePointer* getNext();
        DoubleNodePointer* getPrev();
        Order* getData();
        // Setters
        void setData(Order*);
        void setNext(DoubleNodePointer*);
        void setPrev(DoubleNodePointer*);

};


#endif //INTEGRADORA_CARRITO_DOUBLENODEPOINTER_H
