// CSES 1676 - Road Construction

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;
    int components;
    int maxSize = 1;

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

        components = n;
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
            maxSize = max(maxSize, size[ulp_v]); 
            components--;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            maxSize = max(maxSize, size[ulp_u]);
            components--;
        }
    }

    int getComponents()
    {
        return components;
    }

    int getMax()
    {
        return maxSize; 
    }
};

int main()
{

    int n, m;
    cin >> n >> m;

    DisjointSet ds(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        ds.unionBySize(u, v);
        cout << ds.getComponents() << " " << ds.getMax() << endl;
    }
}

