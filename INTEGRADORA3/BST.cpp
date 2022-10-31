/*
 Created by Armando on 30/10/2022.
*/

#include "BST.h"
#include "Node.h"
#include "NodePtr.h"
#include "Binnacle.h"
#include <iostream>
#include <string>
using namespace std;

BST::BST() {
    root = nullptr;
    size = 0;
}

BST::~BST() {delete root;}

// Getters
NodePtr *BST::getRoot() {return root;}
int BST::getSize() {return size;}

// Setters
void BST::setRoot(NodePtr *root) {BST::root = root;}
void BST::setSize(int size) {BST::size = size;}

// Methods


void BST::insert(NodePtr *node, Binnacle *data) {
    if (data->getIP() < node->getData().getIP()){
        if (node->getLeft() == nullptr){
            node->setLeft(new NodePtr(data));
        }else{
            insert(node->getLeft(), data);
        }
    }else{
        if (node->getRight() == nullptr){
            node->setRight(new NodePtr(data));
        }else{
            insert(node->getRight(), data);
        }
    }
}


