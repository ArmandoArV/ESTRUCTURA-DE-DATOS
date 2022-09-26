#pragma once
#include "nodePtr.h"

class linkedList{
    private:
        NodePtr* head;
    public:
        linkedList();
        ~linkedList();
        NodePtr* getHead();
        void setHead(NodePtr*);
        void eraseByKey(int);
        void insertInOrder(int);
        void recorrer();
        void deleteLastValue();
        void insertAtEnd(int);
        void insertAtStart(int);
        void deleteAtStart();
};