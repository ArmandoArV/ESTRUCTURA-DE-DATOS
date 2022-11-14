/*
 Created by Armando on 14/11/2022.
*/
#include "Graph.h"
#include "Vertex.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

Graph::Graph(int maxNumberOfVertices) { // Time Complexity O(N)
    this->maxNumberOfVertices = maxNumberOfVertices;

    this->numberOfVertices = 0;

    this->vertices.resize(maxNumberOfVertices);
    for (int i = 0; i < maxNumberOfVertices; i++) {
        this->vertices[i] = nullptr;
    }

    this->visited.resize(maxNumberOfVertices);

    this->edges.resize(maxNumberOfVertices, vector<int>(maxNumberOfVertices, 0));
}

Graph::~Graph() {
    for (int i = 0; i < numberOfVertices; i++) {
        delete vertices[i];
    }
}

bool Graph::isEmpty() { // Time Complexity O(1)
    return numberOfVertices == 0;
}

bool Graph::isFull() { // Time Complexity O(1)
    return numberOfVertices == maxNumberOfVertices;
}

void Graph::addVertex(Vertex* vertex) { // Time Complexity O(2N)
    if (isFull()) {
        cout << "Graph is full" << endl;
        return;
    }
    string id = vertex->getId();
    for (int i = 0; i < numberOfVertices; i++) {
        if (vertices[i]->getId() == id) {
            cout << "Vertex already exists" << endl;
            return;
        }
    }

    vertices[numberOfVertices] = vertex;
    for (int i = 0; i < maxNumberOfVertices; i++) {
        edges[numberOfVertices][i] = 0;
        edges[i][numberOfVertices] = 0;
    }
    numberOfVertices++;
}

void Graph::addVertex(string id) { // Time Complexity O(2N)
    if (isFull()) {
        cout << "Graph is full" << endl;
        return;
    }

    for (int i = 0; i < numberOfVertices; i++) {
        if (vertices[i]->getId() == id) {
            cout << "Vertex already exists" << endl;
            return;
        }
    }

    vertices[numberOfVertices] = new Vertex(id, numberOfVertices);
    for (int i = 0; i < maxNumberOfVertices; i++) {
        edges[numberOfVertices][i] = 0;
        edges[i][numberOfVertices] = 0;
    }
    numberOfVertices++;
}

void Graph::addVertex(int id) { // Time Complexity O(2N)
    addVertex(to_string(id));
}

void Graph::addEdge(int from, int to, int weight) { // Time Complexity O(2N)
    if (from < 0 || from >= numberOfVertices) {
        cout << "Invalid from vertex" << endl;
        return;
    }
    if (to < 0 || to >= numberOfVertices) {
        cout << "Invalid to vertex" << endl;
        return;
    }

    int row = indexOfVertex(vertices[from]);
    int column = indexOfVertex(vertices[to]);

    edges[row][column] = weight;
    // Remove this line if the graph is directed
    edges[column][row] = weight;
}

void Graph::addEdge(string from, string to, int weight) { // Time Complexity O(2N)
    int row = indexOfVertex(from);
    int column = indexOfVertex(to);

    if (row == -1 || column == -1) {
        cout << "Invalid vertex" << endl;
        return;
    }


    edges[row][column] = weight;
    // Remove this line if the graph is directed
    edges[column][row] = weight;
}

void Graph::addEdge(string from, string to) { // Time Complexity O(2N)
    int row = indexOfVertex(from);
    int column = indexOfVertex(to);

    if (row == -1 || column == -1) {
        cout << "Invalid vertex" << endl;
        return;
    }

    edges[row][column] = 1;
    // Remove this line if the graph is directed
    edges[column][row] = 1;
}

void Graph::addEdge(int from, int to) { // Time Complexity O(2N)
    if (from < 0 || from >= numberOfVertices) {
        cout << "Invalid from vertex" << endl;
        return;
    }
    if (to < 0 || to >= numberOfVertices) {
        cout << "Invalid to vertex" << endl;
        return;
    }
    int row = indexOfVertex(vertices[from]);
    int column = indexOfVertex(vertices[to]);
    edges[row][column] = 1;
    // Remove this line if the graph is directed
    edges[column][row] = 1;
}

int Graph::weightOfEdge(int from, int to) { // Time Complexity O(2N)
    if (from < 0 || from >= numberOfVertices) {
        cout << "Invalid from vertex" << endl;
        return 0;
    }
    if (to < 0 || to >= numberOfVertices) {
        cout << "Invalid to vertex" << endl;
        return 0;
    }
    int row = indexOfVertex(vertices[from]);
    int column = indexOfVertex(vertices[to]);

    return edges[row][column];
}

int Graph::weightOfEdge(string from, string to) { // Time Complexity O(2N)
    int row = indexOfVertex(from);
    int column = indexOfVertex(to);

    if (row == -1 || column == -1) {
        cout << "Invalid vertex" << endl;
        return 0;
    }

    return edges[row][column];
}

int Graph::indexOfVertex(Vertex* vertex) { // Time Complexity O(N)
    for (int i = 0; i < numberOfVertices; i++) {
        if (vertices[i] == vertex) {
            return i;
        }
    }
    return -1;
}

int Graph::indexOfVertex(string id) { // Time Complexity O(N)
    for (int i = 0; i < numberOfVertices; i++) {
        if (vertices[i]->getId() == id) {
            return i;
        }
    }
    return -1;
}

int Graph::indexOfVertex(int id) { // Time Complexity O(N)
    for (int i = 0; i < numberOfVertices; i++) {
        if (vertices[i]->getId() == to_string(id)) {
            return i;
        }
    }
    return -1;
}

void Graph::clear_visited() { // Time Complexity O(N)
    for (int i = 0; i < numberOfVertices; i++) {
        visited[i] = false;
    }
}

void Graph::markAsVisited(Vertex* vertex) { // Time Complexity O(N)
    int index = indexOfVertex(vertex);
    visited[index] = true;
}

bool Graph::isVisited(Vertex* vertex) { // Time Complexity O(N)
    int index = indexOfVertex(vertex);
    return visited[index];
}

Vertex* Graph::getUnvisitedVertex() { // Time Complexity O(N)
    for (int i = 0; i < numberOfVertices; i++) {
        if (!visited[i]) {
            return vertices[i];
        }
    }
    return nullptr;
}

void Graph::DFS(Vertex* vertex) { // Time Complexity O(N^2)
    if (vertex == nullptr) {
        cout << "Invalid vertex" << endl;
        return;
    }
    stack<Vertex*> s;
    s.push(vertex);
    markAsVisited(vertex);

    while(!s.empty()) {
        Vertex* v = s.top();
        s.pop();
        cout << v->getId() << " ";
        for (int i = 0; i < numberOfVertices; ++i){
            if (edges[indexOfVertex(v)][i] != 0) {
                if (!isVisited(vertices[i])){
                    s.push(vertices[i]);
                    markAsVisited(vertices[i]);
                }
            }
        }
    }
}

void Graph::BFS(Vertex* vertex) { // Time Complexity O(N^2)
    if (vertex == nullptr) {
        cout << "Invalid vertex" << endl;
        return;
    }
    queue<Vertex*> q;
    q.push(vertex);
    markAsVisited(vertex);
    cout << vertex->getId() << " ";

    while (!q.empty()) {
        Vertex* v = q.front();
        q.pop();

        for (int i = 0; i < numberOfVertices; i++) {
            if (edges[indexOfVertex(v)][i] != 0) {
                if (!isVisited(vertices[i])) {
                    q.push(vertices[i]);
                    markAsVisited(vertices[i]);
                    cout << vertices[i]->getId() << " ";
                }
            }
        }
    }
}

void Graph::BFS(string id) { // Time Complexity O(N^2)
    int index = indexOfVertex(id);
    if (index == -1) {
        cout << "Invalid vertex" << endl;
        return;
    }
    BFS(vertices[index]);
}

void Graph::DFS(string id) {  // Time Complexity O(N^2)
    int index = indexOfVertex(id);
    if (index == -1) {
        cout << "Invalid vertex" << endl;
        return;
    }
    DFS(vertices[index]);
}

vector<pair<string, int>> Graph::getNodesAndDegrees() { // Time Complexity O(N^2)
    vector<pair<string, int>> result;
    for (int i = 0; i < numberOfVertices; i++) {
        int degree = 0;
        for (int j = 0; j < numberOfVertices; j++) {
            if (edges[i][j] != 0) {
                degree++;
            }
        }
        result.push_back(make_pair(vertices[i]->getId(), degree));
    }
    return result;
}

vector<Vertex*> Graph::getEdgesOfVertex(string id) { // Time Complexity O(2N)
    int index = indexOfVertex(id);
    if (index == -1) {
        cout << "Invalid vertex" << endl;
        return vector<Vertex*>();
    }
    vector<Vertex*> result;
    for (int i = 0; i < numberOfVertices; i++) {
        if (edges[index][i] != 0) {
            result.push_back(vertices[i]);
        }
    }
    return result;
}