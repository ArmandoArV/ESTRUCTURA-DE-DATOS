/*
    Made by: Armando Arredondo Valle
    Date: 06/10/2022
*/


#include "node.h"
#include "nodePtr.h"

class BinarySearchTree {
    private:
        NodePtr *root;
    public:
        BinarySearchTree();
        ~BinarySearchTree();
        NodePtr* getRoot();
        void setRoot(NodePtr *root);
        void insert(int data);
        void inOrder(NodePtr*);
        void insert();
};