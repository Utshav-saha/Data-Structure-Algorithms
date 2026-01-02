#include <bits/stdc++.h>
using namespace std;

int main()
{

     long long n, m;

    cin >> n >> m;

    vector<vector< long long>> edges;

    for ( long long i = 0; i < m; i++)
    {
         long long u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

     long long src = 1;

    vector< long long> dist(n + 1, 0);
    vector< long long> parent(n + 1, -1);

    dist[src] = 0;
    int flag = 0;
     long long val;

    for ( long long i = 0; i < n; i++)
    {

        for (vector< long long> edge : edges)
        {
             long long u = edge[0];
             long long v = edge[1];
             long long wt = edge[2];
            if (dist[u] + wt < dist[v])
            {

                if (i == n - 1)
                {
                    val = v;
                    flag = -1;
                }

                dist[v] = dist[u] + wt;
                parent[v] = u;
            }
        }
    }

    if (flag == 0)
        cout << "-1" << endl;

    else
    {

        vector< long long> cycle;

        for ( long long i = 0; i < n; i++)
        {
            val = parent[val];
        }

         long long x = val;

        while (true)
        {
            cycle.push_back(x);
            if (x == val && cycle.size() > 1)
                break;
            x = parent[x];
        }

        cycle.pop_back();

        reverse(cycle.begin(), cycle.end());

        // cout << "YES" << endl;

        for (auto it : cycle)
            cout << it << " ";
        cout << endl;
    }

    return 0;
}