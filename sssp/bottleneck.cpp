// gfg - Widest Path Problem (Bottleneck Path) using Modified Dijkstra's Algorithm

#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;

// Structure to represent a graph edge
struct Edge
{
    int to;
    int weight;
};

// Function to find the Bottleneck Path (Maximum Capacity Path)
void bottleneckDijkstra(int n, int source, int destination, const vector<vector<Edge>> &adj)
{

    // dp[i] stores the maximum possible "minimum edge weight"
    // found so far from source to node i.
    // Initialize with -1 (or 0) assuming capacities are positive.
    vector<int> max_capacity(n + 1, -1);

    // Parent array to reconstruct the path
    vector<int> parent(n + 1, -1);

    // Max-Heap: Stores {current_bottleneck_capacity, u}
    // C++ priority_queue is a Max-Heap by default.
    priority_queue<pair<int, int>> pq;

    // Base case: The capacity to the source itself is Infinite
    max_capacity[source] = INF;
    pq.push({INF, source});

    while (!pq.empty())
    {
        int current_cap = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // If we found a path to u with better capacity already, skip
        if (current_cap < max_capacity[u])
            continue;

        // Stop early if we reached destination (optional optimization)
        if (u == destination)
            break;

        for (const auto &edge : adj[u])
        {
            int v = edge.to;
            int weight = edge.weight;

            // The bottleneck of the new path is the minimum of:
            // 1. The bottleneck to reach u
            // 2. The weight of the edge u->v
            int new_bottleneck = min(current_cap, weight);

            // Relaxation: We want to MAXIMIZE the bottleneck
            if (new_bottleneck > max_capacity[v])
            {
                max_capacity[v] = new_bottleneck;
                parent[v] = u;
                pq.push({max_capacity[v], v});
            }
        }
    }

    // Output Results
    if (max_capacity[destination] == -1)
    {
        cout << "No path exists between " << source << " and " << destination << endl;
    }
    else
    {
        cout << "Maximum Bottleneck Capacity: " << max_capacity[destination] << endl;

        // Reconstruct Path
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (size_t i = 0; i < path.size(); i++)
        {
            cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
        }
        cout << endl;
    }
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // Nodes and Edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> adj(n + 1);

    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // Undirected graph
    }

    int source, dest;
    cout << "Enter source and destination: ";
    cin >> source >> dest;

    bottleneckDijkstra(n, source, dest, adj);

    return 0;
}