#include <bits/stdc++.h>
using namespace std;

    int prims(int n, vector<vector<int>> adj[] , vector<pair<int,int>> &edges , int root)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>vis(n,0);
        vector<int> p(n,-1);
        vector<int> dist(n,INT_MAX);
        dist[root] = 0;


        pq.push({0,root});
        int sum = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int node = it.second;

            if(vis[node]) continue;

            vis[node] = 1;
            edges.push_back({p[node], node});
            sum+= w;
            for(auto it : adj[node]){
                int adjNode = it[0];
                int wt = it[1];

                if(!vis[adjNode] && wt < dist[adjNode]){
                    pq.push({wt, adjNode});
                    p[adjNode] = node;
                    dist[adjNode] = wt;
                }

            }
        }

        return sum;
    }

    int main(){

        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj[n];

        for(int i=0; i<m; i++){

            int u,v,w;
            cin >> u>> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        int root ;
        cin >> root;

        vector<pair<int,int>> edges;

        int res = prims(n, adj, edges, root);

        cout << "Total weight " << res << endl;
        cout << "Root node " << root << endl;

        for(int i=1; i< edges.size(); i++){
            cout << edges[i].first<< " " <<edges[i].second << endl;
        }
  
    }