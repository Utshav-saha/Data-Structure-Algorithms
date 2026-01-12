#include <bits/stdc++.h>
using namespace std;


#define V 4

using namespace std;

void printSolution(const vector<vector<int>>& reach) {
    cout << "Transitive Closure Matrix (Reachability):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) 
                cout << "1 "; 
            else
                cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

void transitiveClosure(vector<vector<int>> graph) {
    
    vector<vector<int>> reach = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printSolution(reach);
}

int main() {
    
    vector<vector<int>> graph = {
        {1, 1, 0, 1},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    cout << "Input Graph Adjacency Matrix:" << endl;
    for(auto& row : graph) {
        for(int val : row) cout << val << " ";
        cout << endl;
    }
    cout << "-----------------------------" << endl;

    transitiveClosure(graph);

    return 0;
}