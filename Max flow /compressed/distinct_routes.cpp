// CSES DISTINCT ROUTES


#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    long long to;
    long long capacity;
    bool reverse;
};

bool bfs(vector<vector<Edge>> &residual, long long s, long long t, long long n, vector<long long> &parent, vector<long long> &used)
{

    vector<long long> visited(n, 0);
    fill(parent.begin(), parent.end(), -1);

    queue<long long> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {

        long long u = q.front();
        q.pop();

        for (long long i = 0; i < residual[u].size(); i++)
        {

            Edge e = residual[u][i];

            if (!visited[e.to] && e.capacity > 0)
            {

                parent[e.to] = u;
                visited[e.to] = 1;
                used[e.to] = i;

                if (e.to == t)
                {
                    return true;
                }
                q.push(e.to);
            }
        }
    }

    return false;
}

void ford_fulkerson(vector<vector<Edge>> &residual, long long s, long long t, long long n)
{

    long long maxi = 0;
    vector<long long> parent(n, -1);
    vector<long long> used(n, -1); // adj[u] er kon edge use hoise

    while (bfs(residual, s, t, n, parent, used))
    {

        long long flow = LLONG_MAX;

        long long v = t;
        while (v != s)
        {

            long long u = parent[v];
            long long idx = used[v];

            flow = min(flow, residual[u][idx].capacity);
            v = parent[v];
        }

        // update
        v = t;
        while (v != s)
        {

            long long u = parent[v];
            long long idx = used[v];
            bool type = residual[u][idx].reverse;

            residual[u][idx].capacity -= flow;

            // rev edge find
            for (long long j = 0; j < residual[v].size(); j++)
            {
                if (residual[v][j].to == u && residual[v][j].reverse != type)
                {
                    residual[v][j].capacity += flow;
                    break;
                }
            }

            v = parent[v];
        }

        maxi += flow;
    }
    cout << maxi << endl;
    for (int i = 0; i < maxi; i++)
    {

        int source = 0;
        int dest = n - 1;
        vector<int> path;
        path.push_back(source);

        while (source != dest)
        {

            for (auto &e : residual[source])
            {

                if (!e.reverse && e.capacity == 0)
                {

                    e.capacity = -1;
                    source = e.to;
                    path.push_back(source);
                    break;
                }
            }
        }

        cout << path.size() << endl;
        for (int j = 0; j < path.size(); j++) {
            cout << path[j] + 1 << " ";
        }
        cout << endl;
    }

    // cout << k << endl;
}

int main()
{

    long long n, m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);
    vector<pair<pair<long long, long long>, pair<long long, long long>>> seq;

    for (long long i = 0; i < m; i++)
    {
        long long u, v;
        cin >> u >> v;
        // seq.push_back({{u,v},{0, c}});
        adj[u - 1].push_back({v - 1, 1, false});
        adj[v - 1].push_back({u - 1, 0, true});
    }

    ford_fulkerson(adj, 0, n - 1, n);
    // for(long long i=0; i<m; i++){
    //     long long u = seq[i].first.first;
    //     long long v = seq[i].first.second;
    //     long long c = seq[i].second.second;

    //     for(long long j=0; j<adj[u].size(); j++){
    //         if(adj[u][j].to == v && adj[u][j].capacity <= c && !adj[u][j].reverse){
    //             long long used = c- adj[u][j].capacity;
    //             seq[i].second.first = used;
    //             break;
    //         }
    //     }
    // }

    // cout << ans << endl;
    // for(long long i=0; i<m; i++){
    //     cout << seq[i].first.first << " " << seq[i].first.second << " " << seq[i].second.first <<"/" << seq[i].second.second << endl;
    // }
}