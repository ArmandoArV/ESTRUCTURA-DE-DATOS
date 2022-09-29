/*
    Made by : Armando Arredondo Valle
*/

#include <iostream>
using namespace std;
#include "Node.cpp"
#include "NodePtr.cpp"
#include "linkedList.cpp"
#include "NodePtrTwo.cpp"
#include "linkedListTwo.cpp"

int main(){
    linkedList list;
    linkedListTwo listTwo;
    listTwo.insertInOrder(8);
    listTwo.insertInOrder(12);
    listTwo.insertInOrder(14);
    listTwo.recorrer();
    return 0;
}