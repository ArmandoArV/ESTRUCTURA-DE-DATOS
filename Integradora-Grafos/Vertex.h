/*
 Created by Armando on 14/11/2022.
*/

#ifndef INTEGRADORA_GRAFOS_VERTEX_H
#define INTEGRADORA_GRAFOS_VERTEX_H
#include <string>
#include <iostream>
using namespace std;
class Vertex {
private:
    string id;
    int indexInMatrix;
public:
    Vertex(string id, int index);
    Vertex(int id, int index);
    string getId();
    void setId(string id);
    void setIndexInMatrix(int index);
    int getIndexInMatrix();
};


#endif //INTEGRADORA_GRAFOS_VERTEX_H
