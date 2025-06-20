#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(int node, vector<int> &vis, stack <int> &st, vector <int> adj[])
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, vis, st, adj);
        }

        st.push(node);
    }

    void dfs2(int node, vector<int> &vis, vector <int> adj[])
    {
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs2(it, vis, adj);
        }

    }

public:
    int Kosaraju(int v, vector<int> adj[])
{
    vector<int> vis(v, 0);
    stack<int> st;
    int count = 0;

    // 1. stack according to finishing times
    for (int i = 0; i < v; i++)
        if (!vis[i])
            dfs(i, vis, st, adj);

    // 2. Transpose the graph
    vector<int> adjT[v];
    for (int i = 0; i < v; i++) {
        vis[i] = 0; // Reset for second DFS
        for (auto it : adj[i])
            adjT[it].push_back(i);
    }

    // 3. again dfs
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            count++;
            dfs2(node, vis, adjT);
        }
    }

    return count;
}
};