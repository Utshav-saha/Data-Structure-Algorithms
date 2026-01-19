// UVA 12950 - Even Obsession

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void solve() {
    int C, V;
    while (cin >> C >> V) {
        vector<vector<pair<int, int>>> adj(C + 1);
        
        for (int i = 0; i < V; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<vector<int>> dist(C + 1, vector<int>(2, INF));
        
        // Min-Priority Queue stores tuples: {current_total_cost, current_city, parity_state}
        priority_queue<tuple<int, int, int>, 
                       vector<tuple<int, int, int>>, 
                       greater<tuple<int, int, int>>> pq;

        dist[1][0] = 0;
        pq.push({0, 1, 0});

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            
            int d = get<0>(current); // cost
            int u = get<1>(current); // city
            int p = get<2>(current); // parity

            if (d > dist[u][p]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                int next_parity = 1 - p; 

                if (dist[u][p] + weight < dist[v][next_parity]) {
                    dist[v][next_parity] = dist[u][p] + weight;
                    pq.push({dist[v][next_parity], v, next_parity});
                }
            }
        }

        int ans = dist[C][0];

        if (ans == INF) {
            cout << "-1" << endl;
        } else {
            cout << ans << endl;
        }
    }
}

int main() {

    solve();
    return 0;
}