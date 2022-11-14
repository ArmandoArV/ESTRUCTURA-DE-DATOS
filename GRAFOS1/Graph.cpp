/*
 Created by Armando on 03/11/2022.
*/

#include "Graph.h"
#include <iostream>
#include <list>
using namespace std;

Graph::Graph(int v) {
    this->v = v;
    adj = vector<list<int>>(v);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int s) {
    vector<bool> visited(v, false);
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);
    while (!queue.empty()) {
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

