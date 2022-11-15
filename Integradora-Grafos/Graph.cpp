/*
 Created by Armando on 14/11/2022.
*/

#include "Graph.h"
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

Graph::Graph() {}
Graph::~Graph() {}

void Graph::loadGraph(int id, const Binnacle& binnacle) {
    adjacencyList[id].push_back(binnacle);
}

vector<int> Graph::transformToVector() { // Time Complexity O(n)
    vector<int> vector;
    for (const auto& i : adjacencyList) {
        vector.push_back(i.first);
    }
    sort(vector.begin(),vector.end());
    return vector;
}

vector<pair<int,int>> Graph::topologicalSort(){ // Time Complexity O(n) ^2
    vector<pair<int,int>> v;
    int degree = 0;
    vector<int> vector = transformToVector();
    for (auto i : vector) {
        for (auto j : adjacencyList[i]) {
            degree++;
        }
        v.emplace_back(i,degree);
        degree = 0;
    }
    sort(v.begin(),v.end());
    return v;
}

void Graph::printGraph(int id) {
    for (auto i : adjacencyList[id]) {
        cout << "Day: " << i.getDate().getDay() << " | Month: " << i.getDate().getMonthInt() <<
        " | Hour: " << i.getDate().getHour() << " | Minute: " << i.getDate().getMinute() << " | Second: " << i.getDate().getSecond() <<
        " | IP: " << i.getIP() << " | Port: " << i.getPort() << " | Action: " << i.getReason() << "\n";
    }
}

