/*
    Made by: Armando Arredondo Valle
    Date: 06/10/2022
*/

#include "nodePtr.h"
#include "node.h"
#include <iostream>
using namespace std;

NodePtr::NodePtr(): Node(){
    this->right = NULL;
    this->left = NULL;
    this->parent = NULL;
}

NodePtr::NodePtr(int data): Node(data){
    this->right = NULL;
    this->left = NULL;
    this->parent = NULL;
}

NodePtr::~NodePtr(){}

NodePtr* NodePtr::getRight(){return this->right;}

NodePtr* NodePtr::getLeft(){return this->left;}

NodePtr* NodePtr::getParent(){return this->parent;}

void NodePtr::setRight(NodePtr *right){this->right = right;}

void NodePtr::setLeft(NodePtr *left){this->left = left;}

void NodePtr::setParent(NodePtr *parent){this->parent = parent;}
