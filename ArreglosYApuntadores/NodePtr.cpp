/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/

#include "nodePtr.h"
#include "node.h"
#include <iostream>
using namespace std;

NodePtr::NodePtr(int data):Node(data){this->next = NULL;}
NodePtr::NodePtr():Node(){this->next = NULL;}
NodePtr::NodePtr(int data, NodePtr *next):Node(data){this->next = next;}
NodePtr::~NodePtr(){}
NodePtr* NodePtr::getNext(){return this->next;}
void NodePtr::setNext(NodePtr *next){this->next = next;}

