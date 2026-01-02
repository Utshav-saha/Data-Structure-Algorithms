#include <bits/stdc++.h>
using namespace std;

long long dijkstra(vector<vector<pair<long long, long long>>> &adj, long long src, long long dest)
{

    long long V = adj.size();

    priority_queue<pair<long long, pair<long long, long long>>, vector<pair<long long, pair<long long, long long>>>, greater<pair<long long, pair<long long, long long>>>> pq;
    vector<vector<long long>> dist(V + 1, vector<long long>(2, LLONG_MAX));

    dist[src][0] = 0;
    dist[src][1] = 0;
    pq.push({0, {src, 0}});

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        long long d = top.first;
        long long u = top.second.first;
        long long coupon = top.second.second;

        if (d > dist[u][coupon])
            continue;

        for (auto &p : adj[u])
        {
            long long v = p.first;
            long long w = p.second;

            if (coupon == 0)
            {

                long long d1 = dist[u][0] + w;
                long long d2 = dist[u][0] + w / 2;

                if (d1 < dist[v][0])
                {
                    dist[v][0] = d1;
                    pq.push({d1, {v, 0}});
                }

                if (d2 < dist[v][1])
                {
                    dist[v][1] = d2;
                    pq.push({d2, {v, 1}});
                }
            }

            else
            {
                long long d3 = dist[u][1] + w;
                if (d3 < dist[v][1])
                {
                    dist[v][1] = d3;
                    pq.push({d3, {v, 1}});
                }
            }
        }
    }

    return dist[dest - 1][1];
}

int main()
{

    long long m, n;
    cin >> n >> m;
    long long src = 0;

    vector<vector<pair<long long, long long>>> adj(n);

    for (long long i = 0; i < m; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
    }

    cout << dijkstra(adj, src, n) << endl;

    return 0;
}
