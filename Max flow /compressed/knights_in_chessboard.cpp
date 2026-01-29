#include <bits/stdc++.h>
using namespace std;


struct Edge {
    int to;
    int capacity;
    int rev_idx;
};

bool bfs(vector<vector<Edge>> &residual, int s, int t, int n, vector<int> &parent, vector<int> &edge_idx) {
    vector<bool> visited(n, false);
    fill(parent.begin(), parent.end(), -1);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < residual[u].size(); i++) {
            Edge &e = residual[u][i];
            if (!visited[e.to] && e.capacity > 0) {
                parent[e.to] = u;
                edge_idx[e.to] = i; 
                visited[e.to] = true;
                if (e.to == t) return true;
                q.push(e.to);
            }
        }
    }
    return false;
}

int ford_fulkerson(vector<vector<Edge>> &residual, int s, int t, int n) {
    int max_flow = 0;
    vector<int> parent(n);
    vector<int> edge_idx(n); 

    while (bfs(residual, s, t, n, parent, edge_idx)) {
        int flow = INT_MAX;
        
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            flow = min(flow, residual[u][edge_idx[v]].capacity);
        }

        // Update capacities
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            int idx = edge_idx[v];
            
            residual[u][idx].capacity -= flow;
            
            int reverse_edge_index = residual[u][idx].rev_idx;
            residual[v][reverse_edge_index].capacity += flow;
        }
        max_flow += flow;
    }
    return max_flow;
}

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void solve(int case_num) {
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<bool>> broken(m + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        broken[r][c] = true;
    }

    int s = 0;
    int t = m * n + 1;
    int total_nodes = t + 1;
    vector<vector<Edge>> adj(total_nodes);

    auto get_id = [&](int r, int c) { return (r - 1) * n + c; };

    for (int r = 1; r <= m; r++) {
        for (int c = 1; c <= n; c++) {
            if (broken[r][c]) continue;

            int u = get_id(r, c);

            if ((r + c) % 2 == 0) {
                adj[s].push_back({u, 1, (int)adj[u].size()});
                adj[u].push_back({s, 0, (int)adj[s].size() - 1});

                for (int i = 0; i < 8; i++) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if (nr >= 1 && nr <= m && nc >= 1 && nc <= n && !broken[nr][nc]) {
                        int v = get_id(nr, nc);
                        
                        adj[u].push_back({v, 1, (int)adj[v].size()});
                        adj[v].push_back({u, 0, (int)adj[u].size() - 1});
                    }
                }
            } else {
                adj[u].push_back({t, 1, (int)adj[t].size()});
                adj[t].push_back({u, 0, (int)adj[u].size() - 1});
            }
        }
    }

    int matching = ford_fulkerson(adj, s, t, total_nodes);
    
    int total_available = (m * n) - k;
    cout << "Case " << case_num << ": " << total_available - matching << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
    return 0;
}