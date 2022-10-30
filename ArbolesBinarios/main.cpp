/*
    Made by: Armando Arredondo Valle
    Date: 06/10/2022
*/

#include <iostream>
#include "Node.cpp"
#include "NodePtr.cpp"
#include "binarySearchTree.cpp"

using namespace std;

int main(){
    BinarySearchTree arbol;
    arbol.insert(5);
    arbol.insert(8);
    arbol.insert(4);
    arbol.eraseNode(5);
    arbol.inOrder(arbol.getRoot());
    return 0;
}