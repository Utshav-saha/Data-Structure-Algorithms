// CSES School Dance


#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int capacity;
    bool reverse;
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

                if (e.to == t)
                {
                    return true;
                }
                q.push(e.to);
            }
        }
    }

    return false;
}

int ford_fulkerson(vector<vector<Edge>> &residual, int s, int t, int n)
{

    int maxi = 0;
    vector<int> parent(n, -1);
    vector<int> used(n, -1); // adj[u] er kon edge use hoise

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

        // update
        v = t;
        while (v != s)
        {

            int u = parent[v];
            int idx = used[v];
            bool type = residual[u][idx].reverse;

            residual[u][idx].capacity -= flow;

            // rev edge find
            for (int j = 0; j < residual[v].size(); j++)
            {
                if (residual[v][j].to == u && residual[v][j].reverse != type)
                {
                    residual[v][j].capacity += flow;
                    break;
                }
            }

            v = parent[v];
        }

        maxi += flow;
    }

    return maxi;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    int s = 0;
    int t = n + m + 1;
    int total_nodes = t + 1;

    vector<vector<Edge>> adj(total_nodes);
    vector<pair<int, int>> edges; 

    for (int i = 0; i < k; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v}); 

        adj[u].push_back({v + n, 1, false});
        adj[v + n].push_back({u, 0, true});
    }

    for (int i = 1; i <= n; i++)
    {
        adj[s].push_back({i, 1, false});
        adj[i].push_back({s, 0, true});
    }

    for (int i = n + 1; i <= n + m; i++)
    {
        adj[i].push_back({t, 1, false});
        adj[t].push_back({i, 0, true});
    }

    int ans = ford_fulkerson(adj, s, t, total_nodes);
    cout << ans << endl;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (adj[i][j].to > n && adj[i][j].to <= n + m && adj[i][j].capacity == 0 && !adj[i][j].reverse)
            {
                cout << i << " " << (adj[i][j].to - n) << endl;
            }
        }
    }
}