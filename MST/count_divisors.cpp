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

int power(long long n) {
    int count = 0;
    while (n > 1) {
        n >>= 1;
        count++;
    }
    return count;
}

long long kruskal(int n, vector<pair<int, pair<int, int>>> &edges)
{
    long long weight = 0; 
    
    DisjointSet ds(n);

    int edgesCount = 0;
    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v))
        {   
            weight += wt;
            ds.unionBySize(u, v);
            edgesCount++;
        }
    }

    return weight;
}

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, pair<int, int>>> edges;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        
    
        int exponent = power(w);
        
        edges.push_back({exponent, {u, v}});
    }

    sort(edges.begin(), edges.end());

    long long min_exponent_sum = kruskal(n, edges);

    cout << min_exponent_sum + 1 << endl; 
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}