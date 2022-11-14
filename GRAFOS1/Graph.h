/*
 Created by Armando on 03/11/2022.
*/

#ifndef GRAFOS1_GRAPH_H
#define GRAFOS1_GRAPH_H
#include <vector>
#include <list>
using namespace std;

class Graph {
private:
    int v;
    vector<list<int>> adj;
public:
    Graph(int v);
    Graph();
    void addEdge(int v, int w);
    void BFS(int s);
};


#endif //GRAFOS1_GRAPH_H
