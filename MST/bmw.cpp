// SPOJ BMW

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

void solve()
{
    int n, m;
    if (!(cin >> n >> m)) return;

    
    vector<pair<long long, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges.push_back({w, {u - 1, v - 1}});
    }

    sort(edges.rbegin(), edges.rend());

    DisjointSet ds(n);

    for (auto it : edges)
    {
        long long wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        ds.unionBySize(u, v);

        
        if (ds.findUPar(0) == ds.findUPar(n - 1))
        {
            cout << wt << endl;
            return;
        }
    }

    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}