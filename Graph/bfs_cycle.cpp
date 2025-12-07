#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<int>& vis, vector<int> adj[]) {
    queue<pair<int, int>> q; 
    q.push({start, -1});
    vis[start] = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = 1;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(int v, vector<int> adj[]) {
    vector<int> vis(v, 0);

    for (int i = 0; i < v; i++) {
        if (!vis[i]) {
            if (bfs(i, vis, adj)) return true;
        }
    }
    return false;
}

int main() {
    int v, e;
    cin >> v >> e;

    vector<int> adj[v];
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    if (isCyclic(v, adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}