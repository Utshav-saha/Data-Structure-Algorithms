#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int> &color, vector<int> adj[])
{
    for (auto neighbor : adj[node])
    {
        if (color[neighbor] == -1)
        {
            color[neighbor] = 1 - color[node];
            if (!dfs(neighbor, color, adj))
                return false;
        }
        else if (color[neighbor] == color[node])
        {
            return false;
        }
    }
    return true;
}

bool isBipartite(int n, vector<int> adj[])
{
    vector<int> color(n, -1); 
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0; 
            if (!dfs(i, color, adj))
                return false;
        }
    }
    return true;
}

int main()
{
    int n, m;
    cin >> n >> m; 

    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    if (isBipartite(n, adj))
    {
        cout << "Bipartite" << endl;
    }
    else
    {
        cout << "Not Bipartite" << endl;
    }

    return 0;
}