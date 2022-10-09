/*
    Made by: Armando Arredondo Valle
    Date: 06/10/2022
*/

#pragma once
#include "node.h"
class NodePtr: public Node{
    private:
        NodePtr *right;
        NodePtr *left;
        NodePtr *parent;
    public:
        NodePtr();
        NodePtr(int data);
        ~NodePtr();
        NodePtr* getRight();
        NodePtr* getLeft();
        NodePtr* getParent();
        void setRight(NodePtr *right);
        void setLeft(NodePtr *left);
        void setParent(NodePtr *parent);
};