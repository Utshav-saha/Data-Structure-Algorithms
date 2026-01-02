#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra(vector<vector<pair<long long,long long>>>& adj, long long src, long long k, long long n) {
    
    vector<vector<long long>> dist(n + 1, vector<long long>(k, LLONG_MAX));

    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    dist[src][0] = 0;
    pq.emplace(0, src);

    while (!pq.empty()) {
        long long d = pq.top().first;
        long long u = pq.top().second;
        pq.pop();

        
        if (d > dist[u][k-1]) 
            continue;

        for (auto &p : adj[u]) {
            long long v = p.first;
            long long w = p.second;
            
            long long new_cost = d + w;

            if (new_cost < dist[v][k-1]) {
                
                dist[v][k-1] = new_cost;
                
                sort(dist[v].begin(), dist[v].end());
                
                pq.emplace(new_cost, v);
            }
        }
    }

    return dist[n]; 
}

int main() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return 0;

    vector<vector<pair<long long,long long>>> adj(n + 1);
    for(long long i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    vector<long long> result = dijkstra(adj, 1, k, n);
    
    for (long long d : result) {
        cout << d << " ";
    }
    cout << endl;
    
    return 0;
}