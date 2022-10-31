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

BST::~BST() { delete root; }

// Getters
NodePtr *BST::getRoot() { return root; }

int BST::getSize() { return size; }

// Setters
void BST::setRoot(NodePtr *root) { BST::root = root; }

void BST::setSize(int size) { BST::size = size; }
// Methods


void BST::insertInOrder(Binnacle bitacora) {
    NodePtr *newNode = new NodePtr(bitacora);
    if (root == nullptr) {
        root = newNode;
    } else {
        NodePtr *previous = root, *aux = root;
        while (aux != nullptr && aux->getData() != bitacora) {
            previous = aux;
            if (aux->getData() > bitacora) {
                aux = aux->getLeft();
            } else {
                aux = aux->getRight();
            }
        }
        if (aux != nullptr) {
            cout << "Node already exists" << endl;
            return;
        } else {
            if (previous->getData() < newNode->getData()) {
                previous->setRight(newNode);
            } else {
                previous->setLeft(newNode);
            }
        }
    }
}





void BST::printInOrder(NodePtr *aux) {
    if (aux != nullptr) {
        printInOrder(aux->getLeft());
        cout << aux->getData() << endl; // Aqui
        printInOrder(aux->getRight());
    }
}