// Timus - Ivan's Car

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
{

    int V = adj.size();

    // Min-heap (priority queue) storing pairs of (distance, node and state 0 = down , 1 = up)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<int> dist(V + 1, INT_MAX);

    dist[src] = 0;
    pq.emplace(0, make_pair(src, 0));
    pq.emplace(0, make_pair(src, 1));

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int d = top.first;
        int u = top.second.first;
        int state = top.second.second;


        if (d > dist[u])
            continue;

        for (auto &p : adj[u])
        {
            int v = p.first;
            int w = p.second;

            if (w != state)
            {
                if (dist[u] + 1 <= dist[v])
                {
                    dist[v] = dist[u] + 1;
                    pq.emplace(dist[v], make_pair(v, w));
                }
            }
            else
            {
                if (dist[u] < dist[v])
                {
                    dist[v] = dist[u];
                    pq.emplace(dist[v], make_pair(v, w));
                }
            }
        }
    }

    return dist;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v, 1);
        adj[v].emplace_back(u, 0);
    }

    int src, dest;
    cin >> src >> dest;

    vector<int> result = dijkstra(adj, src);
    if (result[dest] == INT_MAX)
    {
        cout << -1 << " ";
    }
    else
    {
        cout << result[dest] << " ";
    }

    return 0;
}
