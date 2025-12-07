#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;

void solve(int N, int X, long long K, int S, int D, vector<vector<vector<int>>> &adj)
{
    vector<long long> min_cost(N + 1, INF);
    vector<int> min_time(N + 1, 0);
    vector<int> parent(N + 1, -1);

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    min_cost[S] = 0;
    min_time[S] = 0;
    pq.emplace(0, S);

    while (!pq.empty())
    {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > min_cost[u])
            continue;

        if (u == D)
            break;

        for (auto &edge : adj[u])
        {
            int v = edge[0];
            int t = edge[1];
            int c = edge[2];

            long long cost = c + (long long)t * K;
            int time = t;

            if (u != S)
            {
                cost += K;
                time += 1;
            }

            if (min_cost[u] + cost < min_cost[v])
            {
                min_cost[v] = min_cost[u] + cost;
                min_time[v] = min_time[u] + time;
                parent[v] = u;
                pq.emplace(min_cost[v], v);
            }
        }
    }

    if (min_cost[D] == INF)
    {
        cout << "Error" << endl;
    }
    else
    {
        vector<int> path;
        for (int curr = D; curr != -1; curr = parent[curr])
        {
            path.push_back(curr);
        }
        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); i++)
        {
            cout << path[i] << (i == path.size() - 1 ? "" : "->");
        }
        cout << " " << min_time[D] << " " << min_cost[D] << endl;
    }
}

int main()
{
    long long K = 1000;
    int N = 4; // Cities
    int X = 5; // Roads

    // Adjacency List: {neighbor, time, ticket_cost}
    vector<vector<vector<int>>> adj(N + 1);

    // Using vector<int> to represent edges
    adj[1].push_back({2, 1, 2500});
    adj[2].push_back({1, 1, 2500}); // Bidirectional

    adj[1].push_back({3, 1, 3000});
    adj[3].push_back({1, 1, 3000});

    adj[1].push_back({4, 2, 7000});
    adj[4].push_back({1, 2, 7000});

    adj[2].push_back({4, 1, 3000});
    adj[4].push_back({2, 1, 3000});

    adj[3].push_back({4, 1, 2000});
    adj[4].push_back({3, 1, 2000});

    int S = 1, D = 4;

    solve(N, X, K, S, D, adj);

    return 0;
}