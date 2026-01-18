#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> parent, size;

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

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> governments(k);
    vector<bool> govComp(n + 1, false);

    for (int i = 0; i < k; i++)
    {
        cin >> governments[i];
    }

    DisjointSet ds(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ds.unionBySize(u, v);
    }

    int bigGov = -1;
    int maxi = -1;

    for (int gov : governments)
    {
        int root = ds.findUPar(gov);
        govComp[root] = true;

        if (ds.size[root] > maxi)
        {
            maxi = ds.size[root];
            bigGov = root;
        }
    }

    
    for (int i = 1; i <= n; i++)
    {
        int root = ds.findUPar(i);
        if (!govComp[root])
        {
            ds.unionBySize(i, bigGov);
        }
    }

    
    int edge = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (ds.findUPar(i) == ds.findUPar(j))
            {
                edge++;
            }
        }
    }

    cout << edge - m << endl;

    return 0;
}