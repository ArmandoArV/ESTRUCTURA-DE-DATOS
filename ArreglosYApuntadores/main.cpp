/*
    Made by: Antonio Noguerón Bárcenas, Armando Arredondo Valle
    Date: 19/09/2022
*/
#include <iostream>
using namespace std;
#include "Node.cpp"
#include "NodePtr.cpp"
int main(){
    Node node(5);
    cout << node.getData() << endl;
    node.setData(10);
    cout << node.getData() << endl;
    NodePtr *myNode;
    NodePtr *myNode2;
    myNode  = new NodePtr(8);
    myNode2 = new NodePtr(10);
    cout << myNode->getData()<<"\n";
    cout << myNode << "\n";
    cout << myNode2->getData()<<"\n";
    cout << myNode2 << "\n";
    myNode->setNext(myNode2);
    cout << myNode << "\n";
    cout << myNode->getData() << "\n";
    cout << myNode->getNext()->getData() << "\n";
    return 0;
}