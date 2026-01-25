// CSES School Dance


#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to;
    int capacity;
    bool reverse;
};

bool bfs(vector<vector<Edge>> &residual, int s, int t, int n, vector<int> &parent, vector<int> &used)
{

    vector<int> visited(n, 0);
    fill(parent.begin(), parent.end(), -1);

    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {

        int u = q.front();
        q.pop();

        for (int i = 0; i < residual[u].size(); i++)
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

int ford_fulkerson(vector<vector<Edge>> &residual, int s, int t, int n)
{

    int maxi = 0;
    vector<int> parent(n, -1);
    vector<int> used(n, -1); // adj[u] er kon edge use hoise

    while (bfs(residual, s, t, n, parent, used))
    {

        int flow = INT_MAX;

        int v = t;
        while (v != s)
        {

            int u = parent[v];
            int idx = used[v];

            flow = min(flow, residual[u][idx].capacity);
            v = parent[v];
        }

        // update
        v = t;
        while (v != s)
        {

            int u = parent[v];
            int idx = used[v];
            bool type = residual[u][idx].reverse;

            residual[u][idx].capacity -= flow;

            // rev edge find
            for (int j = 0; j < residual[v].size(); j++)
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

    return maxi;
}

int main()
{   
    int t;
    cin >> t;
    while(t--){
    int n, m;
    cin >> m >> n;

    int s = 0;
    int t = n + m + 1;
    int total_nodes = t + 1;

    vector<vector<Edge>> adj(total_nodes);
    vector<pair<int, int>> edges; 
    vector<int> exp(total_nodes,0);
    vector<int> age(total_nodes,0);
    vector<int> record(total_nodes,0);
    vector<int> origin(total_nodes,0);
    vector<int> weapon(total_nodes,0);
    vector<int> trust(total_nodes,0);
    vector<int> lang(total_nodes,0);



    for (int i = 1; i < m+n+1; i++)
    {
        int a,b,c,d,e,f,g;
        cin >> a >> b >> c >> d >> e >> f >> g;

        exp[i]=a;
        age[i]=b;
        record[i]=c;
        origin[i]=d;
        weapon[i]=e;
        trust[i]=f;
        lang[i]=g;
    }

    for (int i = 1; i <= m; i++)
    {
        adj[s].push_back({i, 1, false});
        adj[i].push_back({s, 0, true});
    }

    for (int i = m + 1; i <= n + m; i++)
    {
        adj[i].push_back({t, 1, false});
        adj[t].push_back({i, 0, true});
    }

    for(int i =1;i<=m;i++){
        for(int j=m+1;j<=m+n;j++){
            if(abs(exp[i] - exp[j]) <= 12 && abs(age[i] - age[j]) <= 5 && record[i] == record[j] && origin[i] == origin[j] && (weapon[i] || weapon[j]) && trust[i] + trust[j] >= 10 && (lang[i]&lang[j])){
                adj[i].push_back({j, 1, false});
                adj[j].push_back({i, 0, true});
            }
        }
    }

    int ans = ford_fulkerson(adj, s, t, total_nodes);
    cout << ans << endl;
}
}