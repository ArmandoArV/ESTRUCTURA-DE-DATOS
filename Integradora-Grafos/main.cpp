#include <iostream>
#include "Graph.h"
using namespace std;

bool sortbysec(const pair<string,int> &a, const pair<string,int> &b) { // Time Complexity O(1)
    return (a.second > b.second);
}

int main() {
    cout << "Hello, World!\n";
    return 0;
}
