#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "Date.h"
#include "Binnacle.h"
#include "Graph.h"

using namespace std;

bool sortBySec(const pair<int,int> &a,const pair<int,int> &b) { // Time Complexity O(1)
    return (a.second > b.second);
}
void printGraph(Graph &g, vector<pair<int,int>> &topSort); // Time Complexity O(n)
void printFanInGraph(Graph&, vector<pair<int,int>> &, int , bool ); // Time Complexity O(n)
vector <float> Fan_in(Graph &g, vector<pair<int,int>>&); // Time Complexity O(n)
void Average(vector<float>);
void Median(vector<float>);
void standardDeviation(vector<float>);
Graph graph;

//string test = "C:\\Users\\arman\\OneDrive - Instituto Tecnologico y de Estudios Superiores de Monterrey\\CLASE ESTRUCTURA DE DATOS\\Integradora-Grafos\\cmake-build-debug\\bit.txt";
string original = "C:\\Users\\arman\\OneDrive - Instituto Tecnologico y de Estudios Superiores de Monterrey\\CLASE ESTRUCTURA DE DATOS\\Integradora-Grafos\\cmake-build-debug\\bitacora.txt"; // CAMBIAR AQUI EL PATH DEL ARCHIVO ORIGINAL
int main() {
    int counter = 0;
    int mag;
    bool fan = false;
    vector<float> fan_in;
    string sentences;
    ifstream file(original); // CAMBIAR EN LA VARIABLE EL PATH DEL ARCHIVO ORIGINAL
    if(file.is_open()){
        do{
            getline(file, sentences);
            Date date;
            string IP;
            string port = "";
            string action;
            int spaces = 0;
            string word = "";
            for (int i = 0; i < sentences.size(); i++){
                if (sentences[i] == ' '){
                    spaces++;
                    if (counter == 0){
                        date.setMonth(word);
                        counter++;
                    }
                    else if (counter ==  1){
                        date.setDay(stoi(word));
                        counter++;
                    }
                    else if( counter == 2){
                        date.setHour(stoi(word));
                        date.setMinute(stoi(word.substr(3,2)));
                        date.setSecond(stoi(word.substr(6,2)));
                        counter++;
                    }
                    else if (counter == 3){
                        IP = word;
                        counter++;
                    }
                    word = "";
                    if (spaces == 4){
                        action = sentences.substr(i+1);
                        counter = 0;
                        break;
                    }
                }
                else{
                    word += sentences[i];
                }
            }
            port = IP.substr(IP.find(":")+1);
            IP = IP.substr(0,IP.find(":"));
            Binnacle binnacle(date, IP, port, action);
            // here will insert the binnacle in the linked list
            //binnacleList.appendInOrder(binnacle);
            graph.loadGraph(stoi(port),binnacle);
        } while (!file.fail());
    }else{
        cout << "File not found" << endl;
    }
    vector<pair<int,int>> v = graph.topologicalSort();

    cout << "Ordered graph by port number:\n";
    cout << "==============================\n";
    printGraph(graph,v);

    //cout << "==============================\n";
    cout << "Insert the magnitude of the fan-in: ";
    cin >> mag;
    cout << "Fan-in graph:\n";
    printFanInGraph(graph,v,mag,fan);

    fan_in = Fan_in(graph,v);
    Average(fan_in);
    Median(fan_in);
    standardDeviation(fan_in);
    return 0;
}

void printGraph(Graph &g, vector<pair<int,int>> &topSort) { // Time Complexity O(n)
    sort(topSort.begin(),topSort.end(),sortBySec);
    for (auto & i : topSort) {
        cout << "Port: " << i.first << " | Fan in: " << i.second << endl;
        g.printGraph(i.first);
        cout << "=======================================================================================================\n";
    }
}

void printFanInGraph(Graph &g, vector<pair<int,int>> &topSort, int mag, bool fan) { // Time Complexity O(n)
    for (auto & i : topSort) {
        if (i.second == mag) {
            cout << "Port: " << i.first << " | Fan in: " << i.second << "\n";
            g.printGraph(i.first);
            cout << "=======================================================================================================\n";
        }
    }
}

vector<float> Fan_in(Graph &g, vector<pair<int,int>> &topSort) { // Time Complexity O(n)
    vector<float> fan_in;
    for (auto & i : topSort) {
        fan_in.push_back(i.second);
    }
    return fan_in;
}

void Average(vector<float> fan_in){ // Time Complexity O(n)
    float sum = 0;
    for (float i : fan_in){
        sum += i;
    }
    cout << "Average fan-in: " << sum/fan_in.size() << endl;
}

void Median(vector<float>fan_in){ // Time Complexity O(n)
    sort(fan_in.begin(),fan_in.end());
    if (fan_in.size() % 2 == 0){
        cout << "Median fan-in: " << (fan_in[fan_in.size()/2] + fan_in[(fan_in.size()/2)-1])/2 << endl;
    }
    else{
        cout << "Median fan-in: " << fan_in[fan_in.size()/2] << endl;
    }
}

void standardDeviation(vector<float>fan_in){ // Time Complexity O(n) ^ 2
    float sum = 0;
    float mean = 0;
    float standardDeviation = 0;
    for (float i : fan_in){
        sum += i;
    }
    mean = sum/fan_in.size();
    for (float i : fan_in){
        standardDeviation += pow(i - mean, 2);
    }
    cout << "Standard deviation fan-in: " << sqrt(standardDeviation/fan_in.size()) << endl;
}