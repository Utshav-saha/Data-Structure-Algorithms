#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<long long> dijkstra(vector<vector<pair<long long,long long>>>& adj, long long src, long long n) {
    
    vector<vector<long long>> dist(n + 1, vector<long long>(4, LLONG_MAX));
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    dist[src][0] = 0; // Cost
    dist[src][1] = 0; // Min flights
    dist[src][2] = 0; // Max flights
    dist[src][3] = 1; // Count

    pq.emplace(0, src);

    while (!pq.empty()) {
        long long d = pq.top().first;
        long long u = pq.top().second;
        pq.pop();

        if (d > dist[u][0]) 
            continue;

        for (auto &p : adj[u]) {
            long long v = p.first;
            long long w = p.second;
            
            if (dist[u][0] + w < dist[v][0]) {
                
                dist[v][0] = dist[u][0] + w;
                dist[v][1] = dist[u][1] + 1;
                dist[v][2] = dist[u][2] + 1;
                dist[v][3] = dist[u][3]; 
                
                pq.emplace(dist[v][0], v);
            }
            else if(dist[u][0] + w == dist[v][0]){
                
                dist[v][3] = (dist[v][3] + dist[u][3]) % MOD;
                
                if(dist[u][1] + 1 < dist[v][1]) {
                    dist[v][1] = dist[u][1] + 1;
                }
                
                if(dist[u][2] + 1 > dist[v][2]) {
                    dist[v][2] = dist[u][2] + 1; 
                }
            }
        }
    }

    return dist[n]; 
}

int main() {
    long long n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<pair<long long,long long>>> adj(n + 1);
    for(long long i = 0; i < m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
    }

    vector<long long> result = dijkstra(adj, 1, n);
    
    cout << result[0] << " " << result[3] << " " << result[1] << " " << result[2] << endl;
    
    return 0;
}