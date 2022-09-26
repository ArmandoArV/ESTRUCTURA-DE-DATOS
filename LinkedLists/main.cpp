/*
    Made by : Armando Arredondo Valle
*/

#include <iostream>
using namespace std;
#include "Node.cpp"
#include "NodePtr.cpp"
#include "linkedList.cpp"
int main(){
    linkedList list;
    list.insertInOrder(5);
    list.insertInOrder(3);
    list.insertInOrder(1);
    list.recorrer();
    list.eraseByKey(3);
    list.recorrer();
    list.deleteLastValue();
    list.recorrer();
}