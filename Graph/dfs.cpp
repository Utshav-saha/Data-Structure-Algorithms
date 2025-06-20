#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, vector<int> adj[], vector<int>& res) {
    vis[node] = 1;
    res.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it, vis, adj, res);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> vis(n, 0);
    vector<int> adj[n];

    int start = 0;
    vector<int> res;
    dfs(start, vis, adj, res);

    
    for (int x : res) cout << x << " ";
    cout << endl;
}