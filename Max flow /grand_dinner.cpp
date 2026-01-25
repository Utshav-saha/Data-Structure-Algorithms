// UVA Grand Dinner


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
    int m, n;
    // UVa Problem 10249 requires a loop for multiple test cases
    while (cin >> m >> n && (m != 0 || n != 0))
    {
        int members = 0;
        int s = 0;
        int t = n + m + 1;
        int total_nodes = t + 1;

        vector<vector<Edge>> adj(total_nodes);

        // Input: Teams
        for (int i = 0; i < m; i++)
        {
            int c;
            cin >> c;
            members += c;
            // Edge: Source -> Team (i+1)
            adj[s].push_back({i + 1, c, false});
            adj[i + 1].push_back({s, 0, true});
        }

        // Input: Tables
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            // Edge: Table (i+1+m) -> Sink
            adj[i + 1 + m].push_back({t, c, false});
            adj[t].push_back({i + 1 + m, 0, true});
        }

        // Edges: Team -> Table (Capacity 1)
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Team (i+1) -> Table (j+1+m)
                adj[i + 1].push_back({j + 1 + m, 1, false});
                adj[j + 1 + m].push_back({i + 1, 0, true});
            }
        }

        int ans = ford_fulkerson(adj, s, t, total_nodes);

        if (ans != members)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << "1" << endl;
            
            
            for (int i = 1; i <= m; i++)
            {
                vector<int> team_tables;
                
                for (auto &e : adj[i])
                {
                    if (!e.reverse && e.to > m && e.to <= m + n && e.capacity == 0)
                    {
                        team_tables.push_back(e.to - m);
                    }
                }
                
                for (int k = 0; k < team_tables.size(); k++)
                {
                    cout << team_tables[k] << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}