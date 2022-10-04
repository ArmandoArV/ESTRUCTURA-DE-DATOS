#pragma once
#include "nodePtrTwo.h"
#include "binnacle.h"

class linkedListTwo{
    private:
        NodePtrTwo* head;
    public:
        linkedListTwo();
        ~linkedListTwo();
        NodePtrTwo* getHead();
        void setHead(NodePtrTwo*);
        void recorrer();
        void insertInOrder(int);
        void eraseByData(string);
};