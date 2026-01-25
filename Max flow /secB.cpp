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
                if (e.to == t) return true;
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
        v = t;
        while (v != s)
        {
            int u = parent[v];
            int idx = used[v];
            bool type = residual[u][idx].reverse;
            residual[u][idx].capacity -= flow;
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
    int t;
    cin >> t;
    while(t--)
    {
        int M, H;    
        double R;    
        cin >> M >> H >> R;

        int s = 0;
        int t = M + H + 1;
        int total_nodes = t + 1;

        vector<vector<Edge>> adj(total_nodes);
        
        vector<pair<double, double>> mice(M + 1);
        vector<pair<double, double>> holes(H + 1);
        vector<int> hole_capacity(H + 1);

        for (int i = 1; i <= M; i++)
        {
            cin >> mice[i].first >> mice[i].second;
            
            adj[s].push_back({i, 1, false});
            adj[i].push_back({s, 0, true});
        }

        for (int i = 1; i <= H; i++)
        {
            cin >> holes[i].first >> holes[i].second >> hole_capacity[i];
            
            
            adj[M + i].push_back({t, hole_capacity[i], false});
            adj[t].push_back({M + i, 0, true});
        }

        for(int i = 1; i <= M; i++)
        {
            for(int j = 1; j <= H; j++)
            {
                double dx = mice[i].first - holes[j].first;
                double dy = mice[i].second - holes[j].second;
                double dist = sqrt(dx*dx + dy*dy);

                if(dist <= R) 
                {
                    adj[i].push_back({M + j, 1, false});
                    adj[M + j].push_back({i, 0, true});
                }
            }
        }

        int ans = ford_fulkerson(adj, s, t, total_nodes);
        cout << ans << endl;
    }
}