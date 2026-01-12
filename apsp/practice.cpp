#include <bits/stdc++.h>
using namespace std;

void arbitrage(vector<vector<double>> &dist)
{
    int V = dist.size();

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] < 1e7 && dist[k][j] < 1e7) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main()
{
    int n;
    int caseNum = 1;

    while (cin >> n && n != 0) 
    {
        map<string, int> currency;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            currency[s] = i;
        }

        int m;
        cin >> m;

        vector<vector<double>> dist(n, vector<double>(n, 1e8));

        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            string a, b;
            double c;
            cin >> a >> c >> b;
            dist[currency[a]][currency[b]] = (-log(c));
        }

        arbitrage(dist);

        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (dist[i][i] < 0)
            {
                found = 1;
                break;
            }
        }

        if (found)
        {
            cout << "Case " << caseNum++ << ": Yes" << endl;
        }
        else
        {
            cout << "Case " << caseNum++ << ": No" << endl;
        }
    }
}