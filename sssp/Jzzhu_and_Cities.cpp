// Codeforces - Jzzhu and Cities

#include <bits/stdc++.h>
using namespace std;

long long dijkstra(vector<vector<pair<long long, long long>>> &adj, long long src, long long k, vector<long long> &train)
{
    long long V = adj.size();

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    
    vector<vector<long long>> dist(V, vector<long long>(2));

    for (long long i = 1; i < V; i++)
    {
        if (train[i] != 0)
        {
            dist[i][0] = train[i];
            dist[i][1] = 1; 
            pq.emplace(train[i], i);
        }
        else
        {
            dist[i][0] = LLONG_MAX;
            dist[i][1] = 0;
        }
    }

    dist[src][0] = 0;
    dist[src][1] = 0;
    pq.emplace(0, src);

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        long long d = top.first;
        long long u = top.second;

        if (d > dist[u][0])
            continue;

        for (auto &p : adj[u])
        {
            long long v = p.first;
            long long w = p.second;

            if (dist[u][0] + w < dist[v][0])
            {
                dist[v][0] = dist[u][0] + w;
                dist[v][1] = 0; 
                pq.emplace(dist[v][0], v);
            }
            else if (dist[u][0] + w == dist[v][0]) 
            {
                
                dist[v][1] = 0; 
            }
        }
    }

    long long count = 0;
    for(long long i = 1 ; i < V; i++){
        if(dist[i][1] == 1){
            count++;
        }
    }

    return k - count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<long long, long long>>> adj(n + 1);
    vector<long long> train(n + 1, 0);

    for (long long i = 0; i < m; i++)
    {
        long long u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    for (long long i = 0; i < k; i++) {
        long long v, c;
        cin >> v >> c;
        
        if (train[v] == 0 || c < train[v]) {
            train[v] = c;
        }
        
    }

    long long result = dijkstra(adj, 1, k , train);

    cout << result << " ";

    return 0;
}