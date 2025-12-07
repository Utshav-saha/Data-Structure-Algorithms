#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

void solve() {
    int N, M;
    long long F;
    cin >> N >> M >> F;

    vector<int> capacity(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> capacity[i];
    }

    vector<vector<pair<int, int>>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int K;
    cin >> K;

    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(N + 1, INF);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    
    vector<pair<long long, int>> options;

    for (int i = 1; i <= N; i++) {
        if (dist[i] != INF) {
            options.push_back({dist[i] + F, i});
        }
    }

    sort(options.begin(), options.end());

    
    int idx = 0; 
    vector<long long> results;

    for (int i = 0; i < K; i++) {
        while (idx < options.size() && capacity[options[idx].second] == 0) {
            idx++;
        }

        if (idx < options.size()) {
            
            results.push_back(options[idx].first);
            capacity[options[idx].second]--; 
        } else {
            results.push_back(-1);
        }
    }

    for (int i = 0; i < K; i++) {
        cout << results[i] << (i == K - 1 ? "" : " ");
    }
    cout << endl;
}

