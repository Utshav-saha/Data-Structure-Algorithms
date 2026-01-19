// MST Edge Set Check


#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> parent, size;
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
// ------------------------------

int main()
{
    

    int n, m, q;
    cin >> n >> m >> q;

    // tuple: <weight, u, v, original_index>
    vector<tuple<int, int, int, int>> all_edges;
    vector<tuple<int, int, int, int>> original_lookup; 

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        all_edges.emplace_back(w, u, v, i);
        original_lookup.emplace_back(w, u, v, i);
    }

    // Sort graph edges for Kruskal's logic
    sort(all_edges.begin(), all_edges.end());

    // tuple: <weight, query_id, u, v>
    // We break down queries into individual edges and sort them by weight
    vector<tuple<int, int, int, int>> query_edges_flat;
    
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        while(k--) {
            int idx; cin >> idx; --idx; // 0-based
            // Retrieve edge details
            int w = get<0>(original_lookup[idx]);
            int u = get<1>(original_lookup[idx]);
            int v = get<2>(original_lookup[idx]);
            query_edges_flat.emplace_back(w, i, u, v);
        }
    }
    sort(query_edges_flat.begin(), query_edges_flat.end());

    DisjointSet ds(n);
    vector<bool> ans(q, true); // Assume YES initially

    int edge_ptr = 0;
    int q_ptr = 0;

    // Process both lists by weight
    while (edge_ptr < m || q_ptr < query_edges_flat.size()) {
        int current_w = 2e9;
        if (edge_ptr < m) current_w = min(current_w, get<0>(all_edges[edge_ptr]));
        if (q_ptr < query_edges_flat.size()) current_w = min(current_w, get<0>(query_edges_flat[q_ptr]));

        // 1. Process Queries at this weight
        // We group by query_id to handle multiple edges of same weight in one query
        while (q_ptr < query_edges_flat.size() && get<0>(query_edges_flat[q_ptr]) == current_w) {
            
            int start = q_ptr;
            int current_qid = get<1>(query_edges_flat[q_ptr]);
            
            // Find end of this specific query batch at this weight
            while(q_ptr < query_edges_flat.size() && 
                  get<0>(query_edges_flat[q_ptr]) == current_w && 
                  get<1>(query_edges_flat[q_ptr]) == current_qid) {
                q_ptr++;
            }

            // If this query is already marked NO from a previous (smaller weight) check, skip
            if (!ans[current_qid]) continue;

            // Local DSU simulation (Rollback style)
            // We use a map to simulate a clean DSU for just this batch of edges
            map<int, int> local_parent;
            
            function<int(int)> find_local = [&](int node) {
                if (local_parent.find(node) == local_parent.end()) return node; // Represents itself initially
                if (local_parent[node] == node) return node;
                return local_parent[node] = find_local(local_parent[node]);
            };

            for (int i = start; i < q_ptr; i++) {
                int u = get<2>(query_edges_flat[i]);
                int v = get<3>(query_edges_flat[i]);

                // Get ultimate parents from Main DSU (edges < current_w)
                int root_u = ds.findUPar(u);
                int root_v = ds.findUPar(v);

                if (root_u == root_v) {
                    ans[current_qid] = false; // Cycle with existing MST
                    break;
                }

                // Check cycle within the query edges themselves
                int local_root_u = find_local(root_u);
                int local_root_v = find_local(root_v);

                if (local_root_u == local_root_v) {
                    ans[current_qid] = false; // Cycle within query
                    break;
                }
                
                // Union locally
                local_parent[local_root_u] = local_root_v;
            }
        }

        // 2. Add Graph Edges to Main DSU
        while (edge_ptr < m && get<0>(all_edges[edge_ptr]) == current_w) {
            ds.unionBySize(get<1>(all_edges[edge_ptr]), get<2>(all_edges[edge_ptr]));
            edge_ptr++;
        }
    }

    for (bool val : ans) cout << (val ? "YES" : "NO") << "\n";

    return 0;
}