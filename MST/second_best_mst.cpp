

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

int kruskal(int n, vector<pair<int, int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;

    // Avoid duplicates. Only add edge if u < v
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            int u = i;
            int v = it.first;
            int w = it.second;
            if (u < v)
            {
                edges.push_back({w, {u, v}});
            }
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(n);
    vector<pair<int, int>> mstEdges;
    int first = 0;
    int edge = 0;

    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            mstEdges.push_back({u, v});
            first += wt;
            edge++;
            ds.unionBySize(u, v);
        }
    }

    if (edge < n - 1)
        return -1;

    int second = 1e9;

    for (auto remove : mstEdges)
    {
        DisjointSet ds2(n);
        int currWeight = 0;
        int curredge = 0;

        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (u == remove.first && v == remove.second)
                continue;

            if (ds2.findUPar(u) != ds2.findUPar(v))
            {
                currWeight += wt;
                curredge++;
                ds2.unionBySize(u, v);
            }
        }

        if (curredge == n - 1)
        {
            second = min(second, currWeight);
        }
    }

    if (second == 1e9)
        return -1;

    return second;
}

int main()
{

    
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> adj[n];

        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u - 1].push_back({v - 1, w});
            adj[v - 1].push_back({u - 1, w});
        }

        int res = kruskal(n, adj);
        cout << res << endl;
        return 0;
    
}