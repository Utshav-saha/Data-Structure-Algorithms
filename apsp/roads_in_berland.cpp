// Codeforces - Roads in Berland

#include <bits/stdc++.h>
using namespace std;

int main()
{
   
    int n;
    cin >> n;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> dist[i][j];
        }
    }

    int m; 
    cin >> m;

    while (m--)
    {
        long long u, v, w;
        cin >> u >> v >> w;

        long long sum = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                long long u_v = dist[i][u] + w + dist[v][j];
                long long v_u = dist[i][v] + w + dist[u][j];

                dist[i][j] = min(dist[i][j], min(u_v, v_u));

                if (j > i)
                {
                    sum += dist[i][j];
                }
            }
        }

        cout << sum << " ";
    }

    cout << endl;

    return 0;
}