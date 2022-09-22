/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/
#include "node.h"
class NodePtr: public Node{
    private:
        NodePtr *next;
    public:
        NodePtr(int);
        NodePtr();
        NodePtr(int, NodePtr*);
        ~NodePtr();
        NodePtr* getNext();
        void setNext(NodePtr *next);
};