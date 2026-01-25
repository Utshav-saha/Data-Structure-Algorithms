// CSES POLICE CHASE

#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int capacity;
    bool original; 
};

bool bfs(vector<vector<Edge>> &residual, int s, int t, int n, vector<int> &parent, vector<int> &used)
{
    vector<int> visited(n, 0);
    fill(parent.begin(), parent.end(), -1);

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < residual[u].size(); i++)
        {
            Edge e = residual[u][i];
            if (!visited[e.to] && e.capacity > 0)
            {
                parent[e.to] = u;
                visited[e.to] = 1;
                used[e.to] = i;
                if (e.to == t) return true;
                q.push(e.to);
            }
        }
    }
    return false;
}

void ford_fulkerson(vector<vector<Edge>> &residual, int s, int t, int n)
{
    int maxi = 0;
    vector<int> parent(n, -1);
    vector<int> used(n, -1); 

    while (bfs(residual, s, t, n, parent, used))
    {
        int flow = INT_MAX;
        int v = t;
        while (v != s)
        {
            int u = parent[v];
            int idx = used[v];
            flow = min(flow, residual[u][idx].capacity);
            v = parent[v];
        }

        // update capacities
        v = t;
        while (v != s)
        {
            int u = parent[v];
            int idx = used[v];
            
            residual[u][idx].capacity -= flow;

            // rev edge find
            for (int j = 0; j < residual[v].size(); j++)
            {
                
                if (residual[v][j].to == u) 
                {
                    residual[v][j].capacity += flow;
                    break;
                }
            }
            v = parent[v];
        }
        maxi += flow;
    }

    vector<int> reachable(n, 0);
    queue<int> q;
    q.push(s);
    reachable[s] = 1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (const auto &e : residual[u])
        {
            if (e.capacity > 0 && !reachable[e.to])
            {
                reachable[e.to] = 1;
                q.push(e.to);
            }
        }
    }

    cout << maxi << endl;
    for (int u = 0; u < n; ++u)
    {
        if (reachable[u])
        {
            for (const auto &e : residual[u])
            {
                if (!reachable[e.to] && e.original)
                {
                    cout << u + 1 << " " << e.to + 1 << endl; 
                }
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back({v - 1, 1, true});
        adj[v - 1].push_back({u - 1, 1, true});
    }

    ford_fulkerson(adj, 0, n - 1, n); 
}