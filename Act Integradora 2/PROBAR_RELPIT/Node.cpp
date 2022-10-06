/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/

#include "node.h"
#include "binnacle.h"
#include <iostream>
using namespace std;

Node::Node(Binnacle data){this->data = data;}
Node::Node(){}
Node::~Node(){}
Binnacle Node::getData(){return this->data;}
void Node::setData(Binnacle data){this->data = data;}
