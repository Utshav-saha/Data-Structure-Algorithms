#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

long long kruskal(int n, vector<vector<int>> adj[], vector<pair<int, int>> &mst)
{

    vector<pair<int, pair<int, int>>> edges;
    long long weight = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            int node = i;
            int adjNode = it[0];
            int nodeWt = it[1];

            edges.push_back({nodeWt, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());
    DisjointSet ds(n);

    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            mst.push_back({u, v});
            weight += wt;
            ds.unionBySize(u, v);
        }
    }

    return weight;
}
int main()
{

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj[n];

    for (int i = 0; i < m; i++)
    {

        int u, v, w;
        cin >> u >> v >> w;
        adj[u - 1].push_back({v - 1, w});
        adj[v - 1].push_back({u - 1, w});
    }

    int root;
    cin >> root;

    vector<pair<int, int>> edges;

    long long res = kruskal(n, adj, edges);

    if (edges.size() != n - 1)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << res << endl;
}