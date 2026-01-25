// CSES Assignment Problem 

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int capacity;
    int flow;
    int cost; 
    int rev; 
};

vector<vector<Edge>> adj;
vector<int> dist;
vector<int> parent_edge;
vector<int> parent_node;

void add_edge(int u, int v, int cap, int cost) {
    Edge a = {v, cap, 0, cost, (int)adj[v].size()};
    Edge b = {u, 0, 0, -cost, (int)adj[u].size()}; 
    adj[u].push_back(a);
    adj[v].push_back(b);
}

bool spfa(int s, int t, int &flow, int &cost, int N) {
    dist.assign(N, INF);
    parent_node.assign(N, -1);
    parent_edge.assign(N, -1);
    vector<bool> in_queue(N, false);
    queue<int> q;

    dist[s] = 0;
    q.push(s);
    in_queue[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        for (int i = 0; i < adj[u].size(); i++) {
            Edge &e = adj[u][i];
            
            if (e.capacity - e.flow > 0 && dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost;
                parent_node[e.to] = u;
                parent_edge[e.to] = i;
                
                if (!in_queue[e.to]) {
                    q.push(e.to);
                    in_queue[e.to] = true;
                }
            }
        }
    }

    if (dist[t] == INF) return false;

    int push = 1; 
    int curr = t;
    
    while (curr != s) {
        int prev = parent_node[curr];
        int edge_idx = parent_edge[curr];
        
        adj[prev][edge_idx].flow += push;
        int rev_idx = adj[prev][edge_idx].rev;
        adj[curr][rev_idx].flow -= push;
        
        curr = prev;
    }

    flow += push;
    cost += push * dist[t];
    return true;
}

int main() {
    int n;
    cout << "Enter number of employees/tasks: ";
    cin >> n;

    int s = 0;
    int t = 2 * n + 1;
    adj.resize(t + 1);

    cout << "Enter the cost matrix (" << n << "x" << n << "):" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int c;
            cin >> c;
            
            add_edge(i, n + j, 1, c);
        }
    }

    for (int i = 1; i <= n; i++) {
        add_edge(s, i, 1, 0);
    }

    for (int i = 1; i <= n; i++) {
        add_edge(n + i, t, 1, 0);
    }

    int min_cost = 0;
    int max_flow = 0;

    while (spfa(s, t, max_flow, min_cost, t + 1));

    cout << "Minimum Total Cost: " << min_cost << endl;

    cout << "Assignments:" << endl;
    for (int i = 1; i <= n; i++) {
        for (auto &e : adj[i]) {
            if (e.flow == 1 && e.to > n && e.to <= 2 * n) {
                cout << "Employee " << i << " -> Task " << (e.to - n) << endl;
            }
        }
    }

    return 0;
}