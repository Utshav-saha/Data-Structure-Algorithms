#include <bits/stdc++.h>
using namespace std;

// BFS function to find the parent of each node in the shortest path tree
vector<int> bfs(int v, vector<vector<int>> &adj, int start) {
    vector<int> vis(v + 1, 0);      
    vector<int> parent(v + 1, -1);  
    queue<int> q;

    vis[start] = 1;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                parent[it] = node;
                q.push(it);
            }
        }
    }
    return parent;
}

int main() {
    int m, n;
    cin >> m >> n; // m = number of edges, n = number of nodes (1-indexed)

    vector<vector<int>> adjacency(n + 1); // using standard C++ vector of vectors

    for (int i = 0; i < m-1; i++) {
        int u, v;
        cin >> u >> v;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u); // undirected graph
    }

    int start, dest;
    cin >> start >> dest; 

    vector<int> parent = bfs(n, adjacency, start);

    if (parent[dest] == -1) {
        cout << "No path found" << endl;
        return 0;
    }

    stack<int> st;
    int curr = dest;
    while (curr != -1) {
        st.push(curr);
        curr = parent[curr];
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
