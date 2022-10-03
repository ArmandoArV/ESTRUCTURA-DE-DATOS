#pragma once
#include "nodePtrTwo.h"

class linkedListTwo{
    private:
        NodePtrTwo* head;
    public:
        linkedListTwo();
        ~linkedListTwo();
        NodePtrTwo* getHead();
        void setHead(NodePtrTwo*);
        void recorrer();
        void insertInOrder(Binnacle);
        void eraseByData(Binnacle);
        
};