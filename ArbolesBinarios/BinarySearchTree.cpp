#include "binarySearchTree.h"
#include "nodePtr.h"
#include "node.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){
    this->root = NULL;
}

BinarySearchTree::~BinarySearchTree(){}

NodePtr* BinarySearchTree::getRoot(){return this->root;}

void BinarySearchTree::setRoot(NodePtr *root){this->root = root;}

void BinarySearchTree::inOrder(NodePtr *aux){
    if(aux != NULL){
        inOrder(aux->getLeft());
        cout << aux->getData() << " ";
        inOrder(aux->getRight());
    }
}

void BinarySearchTree::insert(int data){
    NodePtr * newNode = new NodePtr(data);
    if(root == NULL){
        root = newNode;
    }
    else{
        NodePtr *before = root, *aux = root;
        while(aux != NULL && aux->getData() != data){
            before = aux;
            if (aux->getData() > data){
                aux = aux->getLeft();
            }
            else if (aux->getData() == data){
                cout << "This data already exists \n";
                return;
            }
            else
            {
                aux = aux->getRight();
            }
        }
        if (before->getData() < data){
            before->setRight(newNode);
        }else{
            before->setLeft(newNode);
        }
    }
}



void BinarySearchTree::eraseNode(int data){
    if (root == NULL){
        cout << "The tree is empty \n";
        return;
    }
    else {
        NodePtr *before = root, *aux = root;
        while(aux!=NULL && aux->getData() != data){
            before = aux;
            if (aux->getData() > data){
                aux = aux->getLeft();
            }
            
        }
    }
}
