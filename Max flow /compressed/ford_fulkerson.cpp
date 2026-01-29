#include <bits/stdc++.h>
using namespace std;

// BFS to find if there is a path from s to t in the residual graph.
// It also fills the parent[] vector to store the path.
bool bfs(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent)
{
    int V = rGraph.size();
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; v++)
        {
            // If v is not visited and there is residual capacity
            if (!visited[v] && rGraph[u][v] > 0)
            {
                // If we found the sink
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int>> &capacity, int s, int t)
{
    int V = capacity.size();

    // Create a residual graph and fill it with given capacities
    // rGraph[i][j] indicates residual capacity of edge from i to j
    vector<vector<int>> rGraph = capacity;

    // This vector is filled by BFS to store path
    vector<int> parent(V);

    int max_flow = 0; // There is no flow initially

    // Augment the flow while there is a path from source to sink
    while (bfs(rGraph, s, t, parent))
    {

        // Find minimum residual capacity of the edges along the
        // path filled by BFS.
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        // Update residual capacities of the edges and reverse edges
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        // Add path flow to overall flow
        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int v, e;
    cin >> v >> e; // Read vertices and edges

    // Initialize adjacency matrix with 0
    vector<vector<int>> capacity(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++)
    {
        int u, w, cap;
        cin >> u >> w >> cap;
        // Assuming a directed graph.
        // If undirected, you usually add capacity to both [u][w] and [w][u]
        capacity[u][w] = cap;
    }

    // Source is 0, Sink is v-1 (last node)
    cout << fordFulkerson(capacity, 0, v - 1) << endl;

    return 0;
}