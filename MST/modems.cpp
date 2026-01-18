#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;
    int components;

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
            components--;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            components--;
        }
    }

    int getComponents()
    {
        return components;
    }
};

double dist(int x1, int x2, int y1, int y2)
{
    double dx = (double)x1 - x2;
    double dy = (double)y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

pair<double, double> kruskal(int n, vector<vector<double>> adj[], int &w)
{
    vector<pair<double, tuple<int, int, int>>> edges;
    double weight1 = 0;
    double weight2 = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            int node = i;
            int adjNode = (int)it[0];
            double nodeWt = it[1];
            int state = (int)it[2];

            edges.push_back({nodeWt, make_tuple(node, adjNode, state)}); 
        }
    }

    sort(edges.begin(), edges.end());
    DisjointSet ds(n);

    for (auto it : edges)
    {

        if (ds.getComponents() == w) 
        {
            break;
        }

        double wt = it.first;
        int u = get<0>(it.second); 
        int v = get<1>(it.second);
        int state = get<2>(it.second);

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            if (state == 0)
            {
                weight1 += wt;
            }
            else
            {
                weight2 += wt;
            }

            ds.unionBySize(u, v);
        }
    }

    return {weight1, weight2};
}

int main()
{
    int t;
    if (cin >> t) { 
        for (int i = 0; i < t; i++)
        {
            int n, r, w;
            double u, v; 

            cin >> n >> r >> w >> u >> v;
            
            vector<int> modem_x(n);
            vector<int> modem_y(n);
            
            for (int k = 0; k < n; k++)
            {
                cin >> modem_x[k] >> modem_y[k];
            }

            vector<vector<double>> adj[n]; 
            
            for (int k = 0; k < n; k++)
            {
                for (int j = k + 1; j < n; j++)
                {
                    double distance = dist(modem_x[k], modem_x[j], modem_y[k], modem_y[j]);
                    if (distance <= r)
                    {
                        adj[k].push_back({(double)j, u * distance, 0.0});
                        adj[j].push_back({(double)k, u * distance, 0.0});
                    }
                    else
                    {
                        adj[k].push_back({(double)j, v * distance, 1.0});
                        adj[j].push_back({(double)k, v * distance, 1.0});
                    }
                }
            }

            cout << "Caso #" << i + 1 << ": ";
            pair<double, double> res = kruskal(n, adj, w);
            cout << fixed << setprecision(3) << res.first << " " << fixed << setprecision(3) << res.second << "\n";
        }
    }
    return 0;
}