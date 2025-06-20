#include <bits/stdc++.h>
using namespace std;

int main(){
    int m , n;
    cin >>m >> n;

    // Adjacency Matrix Representation
    int adj[n+1][n+1];
    for(int i=0; i<m; i++){
        int u , v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Adjacency List Representation
    vector <int> adjacency[n+1];
    for(int i=0; i<m; i++){
        int u , v;
        
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }
}