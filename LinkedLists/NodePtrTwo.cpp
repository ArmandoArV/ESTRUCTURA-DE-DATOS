#include "node.h"
#include "nodePtrTwo.h"
#include <iostream>

using namespace std;

NodePtrTwo::NodePtrTwo(int data):Node(data){
    this->next = NULL;
    this->before = NULL;
}

NodePtrTwo::NodePtrTwo():Node(){
    this->next = NULL;
    this->before = NULL;
}

NodePtrTwo::NodePtrTwo(int data, NodePtrTwo *before, NodePtrTwo *next):Node(data){
    this->next = next;
    this->before = before;
}

NodePtrTwo::~NodePtrTwo(){}

NodePtrTwo* NodePtrTwo::getNext(){return this->next;}
NodePtrTwo* NodePtrTwo::getBefore(){return this->before;}
void NodePtrTwo::setNext(NodePtrTwo *next){this->next = next;}
void NodePtrTwo::setBefore(NodePtrTwo *before){this->before = before;}
