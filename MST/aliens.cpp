//http://poj.org/problem?id=3026


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

int kruskal(int n, vector<vector<vector<int>>> &adj, vector<pair<int, int>> &mst)
{
    vector<pair<int, pair<int, int>>> edges;
    int weight = 0;

    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            int node = i;
            int adjNode = it[0];
            int nodeWt = it[1];
            
            if (node < adjNode) {
                edges.push_back({nodeWt, {node, adjNode}});
            }
        }
    }

    sort(edges.begin(), edges.end());
    DisjointSet ds(n);

    for (auto it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUPar(u) != ds.findUPar(v))
        {
            mst.push_back({u, v});
            weight += wt;
            ds.unionBySize(u, v);
        }
    }

    return weight;
}

void bfs_distances(int startNodeIndex, int sx, int sy, int R, int C, const vector<string> &grid, 
                   const vector<vector<int>> &nodeIdMap, vector<vector<vector<int>>> &adj) {
    
    vector<vector<int>> dist(R, vector<int>(C, -1));
    queue<pair<int, int>> q;

    q.push({sx, sy});
    dist[sy][sx] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        
        if (nodeIdMap[cy][cx] != -1 && dist[cy][cx] > 0) {
            int targetNodeIndex = nodeIdMap[cy][cx];
            int weight = dist[cy][cx];
            adj[startNodeIndex].push_back({targetNodeIndex, weight});
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dc[i];
            int ny = cy + dr[i];

            if (nx >= 0 && nx < C && ny >= 0 && ny < R && 
                grid[ny][nx] != '#' && dist[ny][nx] == -1) {
                dist[ny][nx] = dist[cy][cx] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    int C, R; 
    if (!(cin >> C >> R)) return; 

    vector<string> grid(R);
    vector<pair<int,int>> nodes; 
    
    vector<vector<int>> nodeIdMap(R, vector<int>(C, -1)); 

    for (int i = 0; i < R; i++) {
        getline(cin, grid[i]); 
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'S' || grid[i][j] == 'A') {
                nodeIdMap[i][j] = nodes.size();
                nodes.push_back({j, i}); 
            }
        }
    }

    int n = nodes.size(); 
    
    vector<vector<vector<int>>> adj(n);

    for (int i = 0; i < n; i++) {
        bfs_distances(i, nodes[i].first, nodes[i].second, R, C, grid, nodeIdMap, adj);
    }

    vector<pair<int, int>> mst;
    int res = kruskal(n, adj, mst);

    cout << res << endl;
}

int main()
{
    int num_test_cases;
    cin >> num_test_cases;
    while(num_test_cases--) {
        solve();
    }
    return 0;
}