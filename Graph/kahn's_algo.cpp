#include <bits/stdc++.h>
using namespace std;

vector<int> kahn(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0) q.push(v);
        }
    }

    return topo;
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v; 
        adj[u].push_back(v);
    }

    vector<int> topo = kahn(n, adj);

    if (topo.size() < n) {
        cout << "Cycle detected, topological sort not possible\n";
    } else {
        for (int x : topo) cout << x << " ";
        cout << endl;
    }
}