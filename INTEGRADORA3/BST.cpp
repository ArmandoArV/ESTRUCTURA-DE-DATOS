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

void BST::deleteNode(Binnacle bitacora) {
    NodePtr *aux = root, *previous = root;
    while (aux != nullptr && aux->getData() != bitacora) {
        previous = aux;
        if (aux->getData() > bitacora) {
            aux = aux->getLeft();
        } else {
            aux = aux->getRight();
        }
    }
    if (aux == nullptr) {
        cout << "Node not found" << endl;
        return;
    } else {
        if (aux->getLeft() == nullptr && aux->getRight() == nullptr) {
            if (previous->getLeft() == aux) {
                previous->setLeft(nullptr);
            } else {
                previous->setRight(nullptr);
            }
            delete aux;
        } else if (aux->getLeft() != nullptr && aux->getRight() != nullptr) {
            NodePtr *aux2 = aux->getRight();
            while (aux2->getLeft() != nullptr) {
                aux2 = aux2->getLeft();
            }
            aux->setData(aux2->getData());
            if (aux2->getRight() != nullptr) {
                aux2->setData(aux2->getRight()->getData());
                aux2->setRight(aux2->getRight()->getRight());
            } else {
                aux2->setData(aux2->getLeft()->getData());
                aux2->setLeft(aux2->getLeft()->getLeft());
            }
        } else {
            if (aux->getLeft() != nullptr) {
                if (previous->getLeft() == aux) {
                    previous->setLeft(aux->getLeft());
                } else {
                    previous->setRight(aux->getLeft());
                }
            } else {
                if (previous->getLeft() == aux) {
                    previous->setLeft(aux->getRight());
                } else {
                    previous->setRight(aux->getRight());
                }
            }
            delete aux;
        }
    }
}

void BST::preOrder(NodePtr *aux) {
    if (aux != nullptr) {
        cout << aux->getData() << endl; // Aqui
        preOrder(aux->getLeft());
        preOrder(aux->getRight());
    }
}

void BST::posOrder(NodePtr *aux) {
    if (aux != nullptr) {
        posOrder(aux->getLeft());
        posOrder(aux->getRight());
        cout << aux->getData() << endl;
    }
}

void BST::deleteLeaf(NodePtr *aux, NodePtr *previous) {
    if (aux == root)
        root = nullptr;
    else {
        if (aux == previous->getRight())
            previous->setRight(nullptr);
        else
            previous->setLeft(nullptr);
        delete aux;
    }
}

void BST::deleteOneChild(NodePtr *aux, NodePtr *previous) {
    cout << "Delete node with a child\n";
    if (aux == root) {
        if (aux->getRight() != nullptr)
            root = aux->getRight();
        else
            root = aux->getLeft();
    } else {
        if (aux->getRight() != nullptr)          // el que borro tiene hijo derecho
            if (previous->getRight() == aux)       // es hijo derecho
                previous->setRight(aux->getRight()); // sustituyo por su hijo derecho
            else
                previous->setLeft(aux->getRight());
        else {
            if (previous->getRight() == aux)
                previous->setRight(aux->getLeft());
            else
                previous->setLeft(aux->getLeft());
        }
    }
    delete aux;
}
void deleteTwoChild(NodePtr *aux, NodePtr *previous){
    cout << "Delete node with two children\n";
    NodePtr *aux2 = aux->getRight();
    while (aux2->getLeft() != nullptr)
        aux2 = aux2->getLeft();
    aux->setData(aux2->getData());
    if (aux2->getRight() != nullptr)
        aux2->setData(aux2->getRight()->getData());
    else
        aux2->setData(aux2->getLeft()->getData());
    if (aux2->getRight() != nullptr)
        aux2->setRight(aux2->getRight()->getRight());
    else
        aux2->setLeft(aux2->getLeft()->getLeft());
}
