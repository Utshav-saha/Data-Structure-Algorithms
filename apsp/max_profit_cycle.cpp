

#include <bits/stdc++.h>
using namespace std;

void arbitrage(vector<vector<double>> &dist, vector<vector<int>> &parent)
{
    int V = dist.size();

    for (int k = 0; k < V; k++)
    {

        for (int i = 0; i < V; i++)
        {

            for (int j = 0; j < V; j++)
            {

                if (dist[i][k] != 1e8 && dist[k][j] != 1e8)
                {
                    double newDist = dist[i][k] + dist[k][j];
                    if (newDist < dist[i][j])
                    {
                        dist[i][j] = newDist;
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n;
    map<string, int> currency;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        currency[s] = i;
    }
    cin >> m;

    vector<vector<double>> dist(n, vector<double>(n, 1e8));
    vector<vector<int>> parent(n, vector<int>(n, 1e8));

    for (int i = 0; i < n; i++)
    {
        dist[i][i] = 0;
        parent[i][i] = i;
    }

    for (int i = 0; i < m; i++)
    {
        string a, b;
        double c;
        cin >> a >> c >> b;
        dist[currency[a]][currency[b]] = (-log(c));
        parent[currency[a]][currency[b]] = currency[a];
    }

    arbitrage(dist, parent);

    int min = 0;
    double profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist[i][i] < profit)
        {
            profit = dist[i][i];
            min = i;
        }
    }

    if (dist[min][min] < 0)
    {

        cout << "Yes" << endl;
        vector<int> cycle;
        cycle.push_back(min);
        int curr = parent[min][min];
        while (curr != min)
        {
            cycle.push_back(curr);
            curr = parent[min][curr];
        }
        cycle.push_back(min);

        reverse(cycle.begin(), cycle.end());

        for (auto node : cycle)
        {
            for (auto &pair : currency)
            {
                if (pair.second == node)
                {
                    cout << pair.first << " ";
                }
            }
        }
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
