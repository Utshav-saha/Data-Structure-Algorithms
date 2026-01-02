#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<long long, long long>>> &adj, long long src)
{
    long long n = adj.size();
    vector<long long> dist(n, LONG_MAX);

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        long long d = top.first;
        long long u = top.second;

        if (d > dist[u])
            continue;

        for (auto &p : adj[u])
        {
            long long v = p.first;
            long long w = p.second;

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    long long n, m,q;
    cin >> n >> m >> q;

    vector<vector<pair<long long, long long>>> adj(n);

    for (long long i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back({v-1, w});
        adj[v-1].push_back({u-1, w});
    }

    vector<long long> result = dijkstra(adj, 0);

    for (long long d : result)
    {
        if (d == LONG_MAX)
            cout << "INF "; 
        else
            cout << d << " ";
    }
    cout << endl;

    return 0;
}