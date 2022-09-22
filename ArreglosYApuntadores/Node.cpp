/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/

#include "node.h"
#include <iostream>
using namespace std;

Node::Node(int data){this->data = data;}
Node::Node(){this->data = 0;}
Node::~Node(){}
int Node::getData(){return this->data;}
void Node::setData(int data){this->data = data;}
