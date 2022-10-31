/*
 Created by Armando on 30/10/2022.
*/

#ifndef INTEGRADORA3_NODE_H
#define INTEGRADORA3_NODE_H
#include "Binnacle.h"

using namespace std;

class Node {
private:
    Binnacle data;
public:
    Node(Binnacle data);
    Node();
    ~Node();
    // Getters
    Binnacle getData();
    // Setters
    void setData(Binnacle data);

};


#endif //INTEGRADORA3_NODE_H
