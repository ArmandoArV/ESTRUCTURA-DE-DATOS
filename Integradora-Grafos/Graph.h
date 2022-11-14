/*
 Created by Armando on 14/11/2022.
*/
#include "Vertex.h"
#include <vector>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

#pragma once
class Graph {
private:
    vector<Vertex*> vertices;
    vector<bool> visited;
    int numberOfVertices;
    int maxNumberOfVertices;
    vector<vector<int>> edges;
public:

    Graph(int maxNumberOfVertices);
    ~Graph();

    void addVertex(Vertex* vertex);
    void addVertex(string id);
    void addVertex(int id);
    void addEdge(int from, int to, int weight);
    void addEdge(int from, int to);
    void addEdge(string from, string to, int weight);
    void addEdge(string from, string to);
    int weightOfEdge(int from, int to);
    int weightOfEdge(string from, string to);
    int indexOfVertex(Vertex* vertex);
    int indexOfVertex(string id);
    int indexOfVertex(int id);
    void clear_visited();
    void markAsVisited(Vertex* vertex);
    bool isVisited(Vertex* vertex);
    Vertex* getUnvisitedVertex();
    vector<Vertex*> getEdgesOfVertex(string id);
    void DFS(Vertex* vertex);
    void BFS(Vertex* vertex);
    void DFS(string id);
    void BFS(string id);

    vector<pair<string, int>> getNodesAndDegrees();

    bool isEmpty();
    bool isFull();
};
