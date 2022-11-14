/*
 Created by Armando on 14/11/2022.
*/
#include "Vertex.h"
#include <iostream>
#include <string>
using namespace std;

Vertex::Vertex(string id, int index) { // Time Complexity O(1)
    this->id = id;
    this->indexInMatrix = index;
}

Vertex::Vertex(int id, int index) { // Time Complexity O(1)
    this->id = to_string(id);
    this->indexInMatrix = index;
}

string Vertex::getId() { // Time Complexity O(1)
    return id;
}

void Vertex::setId(string id_) { // Time Complexity O(1)
    id = id_;
}

void Vertex::setIndexInMatrix(int index) { // Time Complexity O(1)
    indexInMatrix = index;
}

int Vertex::getIndexInMatrix() { // Time Complexity O(1)
    return indexInMatrix;
}

