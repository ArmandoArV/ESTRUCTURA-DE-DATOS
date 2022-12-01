/*
 Created by Armando on 30/11/2022.
*/

#include "DoubleNodePointer.h"
#include <iostream>

DoubleNodePointer::DoubleNodePointer() {
    next = nullptr;
    prev = nullptr;
}

DoubleNodePointer::DoubleNodePointer(Order* data) {
    this->data = data;
    next = nullptr;
    prev = nullptr;
}

DoubleNodePointer::~DoubleNodePointer() {delete data;}

// Getters
DoubleNodePointer* DoubleNodePointer::getNext() {return next;}
DoubleNodePointer* DoubleNodePointer::getPrev() {return prev;}
Order* DoubleNodePointer::getData() {return data;}
// Setters
void DoubleNodePointer::setData(Order* data) {this->data = data;}
void DoubleNodePointer::setNext(DoubleNodePointer* next) {this->next = next;}
void DoubleNodePointer::setPrev(DoubleNodePointer* prev) {this->prev = prev;}
