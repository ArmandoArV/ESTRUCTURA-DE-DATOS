/*
 Created by Armando on 30/10/2022.
*/

#include "NodePtr.h"
#include "Binnacle.h"
#include <iostream>
using namespace std;

NodePtr::NodePtr() {
    this->right = nullptr;
    this->left = nullptr;
    this->parent = nullptr;
}

NodePtr::NodePtr(Binnacle data) {
    this->right = nullptr;
    this->left = nullptr;
    this->parent = nullptr;
}

NodePtr::~NodePtr() {

}

// Getters
NodePtr *NodePtr::getRight() {return this->right;}
NodePtr *NodePtr::getLeft() {return this->left;}
NodePtr *NodePtr::getParent() {return this->parent;}

// Setters
void NodePtr::setRight(NodePtr *right) {this->right = right;}
void NodePtr::setLeft(NodePtr *left) {this->left = left;}
void NodePtr::setParent(NodePtr *parent) {this->parent = parent;}

