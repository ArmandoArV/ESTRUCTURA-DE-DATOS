/*
 Created by Armando on 30/10/2022.
*/

#ifndef INTEGRADORA3_BST_H
#define INTEGRADORA3_BST_H
#include "Node.h"
#include "NodePtr.h"
#include "Binnacle.h"
#include <iostream>
#include <string>
using namespace std;


class BST {
private:
    NodePtr *root;
    int size;
public:
    BST();
    ~BST();
    // Getters
    NodePtr *getRoot();
    int getSize();
    // Setters
    void setRoot(NodePtr *root);
    void setSize(int size);
    // Methods
    void insert(NodePtr *node, Binnacle *data);
    void print();
};


#endif //INTEGRADORA3_BST_H
