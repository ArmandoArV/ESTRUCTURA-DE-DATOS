/*
Armando Arredondo Valle
    Date: 19/09/2022
*/

#include "Node.h"
#include "Binnacle.h"
#include <iostream>
using namespace std;

Node::Node(Binnacle data){this->data = data;}
Node::Node(){}
Node::~Node(){}
Binnacle Node::getData(){return this->data;}
void Node::setData(Binnacle data){this->data = data;}
