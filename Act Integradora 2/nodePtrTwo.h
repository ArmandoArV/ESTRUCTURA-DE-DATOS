/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/
#pragma once
#include "node.h"
#include "binnacle.h"
class NodePtrTwo: public Node{
    private:
        NodePtrTwo *before;
        NodePtrTwo *next;
    public:
        NodePtrTwo(Binnacle);
        NodePtrTwo();
        NodePtrTwo(Binnacle, NodePtrTwo*, NodePtrTwo*);
        ~NodePtrTwo();
        NodePtrTwo* getNext();
        NodePtrTwo* getBefore();
        void setNext(NodePtrTwo *next);
        void setBefore(NodePtrTwo *before);
};