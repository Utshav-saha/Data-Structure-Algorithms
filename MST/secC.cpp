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

void solve(int n, vector<vector<int>> adj[], vector<bool> &isRisky, int P, vector<int> &safeCities)
{
    vector<pair<int, pair<int, int>>> safeEdges;
    vector<pair<int, pair<int, int>>> riskyEdges;

    for (int u = 0; u < n; u++)
    {
        for (auto it : adj[u])
        {
            int v = it[0];
            int w = it[1];

            if (u < v)
            {
                int riskCount = (isRisky[u] ? 1 : 0) + (isRisky[v] ? 1 : 0);

                if (riskCount == 0)
                {
                    safeEdges.push_back({w, {u, v}});
                }
                else
                {
                    int effective_w = w + (riskCount * P);
                    riskyEdges.push_back({effective_w, {u, v}});
                }
            }
        }
    }

    sort(safeEdges.begin(), safeEdges.end());
    sort(riskyEdges.begin(), riskyEdges.end());

    DisjointSet ds(n);
    vector<pair<int, int>> mstEdges;
    long long totalCost = 0;

    for (auto it : safeEdges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            ds.unionBySize(u, v);
            mstEdges.push_back({u, v});
            totalCost += wt;
        }
    }

    for (auto it : riskyEdges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            ds.unionBySize(u, v);
            mstEdges.push_back({u, v});
            totalCost += wt;
        }
    }

    if (safeCities.empty())
    {
        cout << 0 << endl;
        cout << 0 << endl;
        return;
    }

    int rootSafe = ds.findUPar(safeCities[0]);
    bool possible = true;
    for (size_t i = 1; i < safeCities.size(); i++)
    {
        if (ds.findUPar(safeCities[i]) != rootSafe)
        {
            possible = false;
            break;
        }
    }

    if (!possible)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mstEdges.size() << endl;
        for (auto it : mstEdges)
        {
            cout << it.first << " " << it.second << endl;
        }
        cout << totalCost << endl;
    }
}

int main()
{
    int n, m, P;
    if (!(cin >> n >> m >> P))
        return 0;

    int k;
    cin >> k;

    vector<bool> isRisky(n, false);
    for (int i = 0; i < k; i++)
    {
        int r;
        cin >> r;
        isRisky[r] = true;
    }

    vector<int> safeCities;
    for (int i = 0; i < n; i++)
    {
        if (!isRisky[i])
            safeCities.push_back(i);
    }

    vector<vector<int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    solve(n, adj, isRisky, P, safeCities);

    return 0;
}