/*
 Created by Armando on 14/11/2022.
*/

#ifndef INTEGRADORA_GRAFOS_GRAPH_H
#define INTEGRADORA_GRAFOS_GRAPH_H
#include "Binnacle.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;


class Graph {
private:
    map<Binnacle,bool>visited;
    map<int, list<Binnacle>>adjacencyList;
public:
    Graph();
    ~Graph();
    void loadGraph(int,const Binnacle&);
    vector<int>transformToVector();
    vector<pair<int,int>> topologicalSort();
    void printGraph(int);
};


#endif //INTEGRADORA_GRAFOS_GRAPH_H
