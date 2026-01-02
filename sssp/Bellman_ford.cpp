#include <bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    
    
	vector<int> dist(V, 1e8);
	dist[src] = 0;
  
	
	for (int i = 0; i < V; i++) {
	    
		for (vector<int> edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
			    
                
                if(i == V - 1)
                    return {-1};
               
                dist[v] = dist[u] + wt;
            }
		}
	}

    return dist;
}

int main() {
    
    // Number of vertices in the graph
    int n , m;

    cin >> n >> m;

    // Edge list representation: {source, destination, weight}
    vector<vector<int>> edges;

    for(int i=0; i<m; i++){
        int u , v , w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    // Define the source vertex
    int src = 0;

    // Run Bellman-Ford algorithm to get shortest paths from src
    vector<int> ans = bellmanFord(n, edges, src);

    // Output the shortest distances from src to all vertices
    for (int dist : ans) 
        cout << dist << " ";

    return 0; 
}