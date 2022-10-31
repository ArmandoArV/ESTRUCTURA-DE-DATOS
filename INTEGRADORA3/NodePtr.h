/*
 Created by Armando on 30/10/2022.
*/

#ifndef INTEGRADORA3_NODEPTR_H
#define INTEGRADORA3_NODEPTR_H
#include "Node.h"
#include <iostream>
#include <string>
#include "Binnacle.h"
using namespace std;

class NodePtr: public Node {
private:
    Binnacle *data;
    NodePtr *right;
    NodePtr *left;
    NodePtr *parent;
public:
    NodePtr();
    NodePtr(Binnacle *data);
    ~NodePtr();
    // Getters
    NodePtr *getRight();
    NodePtr *getLeft();
    NodePtr *getParent();
    // Setters
    void setRight(NodePtr *right);
    void setLeft(NodePtr *left);
    void setParent(NodePtr *parent);
};


#endif //INTEGRADORA3_NODEPTR_H
