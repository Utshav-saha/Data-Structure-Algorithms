// SPOJ FASTFLOW


#include <bits/stdc++.h>
using namespace std;

struct Edge{
    long long to;
    long long capacity; 
    bool reverse;

};

bool bfs(vector<vector<Edge>> &residual , long long s , long long t, long long n, vector<long long>& parent , vector<long long> &used){

    vector<long long> visited(n,0);
    fill(parent.begin(), parent.end(), -1);

    queue<long long> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1;

    while(!q.empty()){

        long long u = q.front();
        q.pop();

        for(long long i=0; i< residual[u].size(); i++){

            Edge e = residual[u][i];

            if(!visited[e.to] && e.capacity > 0){

                parent[e.to] = u;
                visited[e.to] = 1;
                used[e.to] = i;

                if(e.to == t){
                    return true;
                }
                q.push(e.to);
            }
        }

    }

    return false;

}

long long ford_fulkerson(vector<vector<Edge>> &residual, long long s , long long t, long long n){

    long long maxi = 0;
    vector<long long> parent(n,-1);
    vector<long long> used(n, -1);    // adj[u] er kon edge use hoise

    while(bfs(residual, s, t, n,parent, used)){

        long long flow = LLONG_MAX;

        long long v = t;
        while(v!= s){

            long long u = parent[v];
            long long idx = used[v];
            

            flow = min(flow , residual[u][idx].capacity);
            v = parent[v];
        }

        // update
        v = t;
        while(v!= s){

            long long u = parent[v];
            long long idx = used[v];
            bool type =residual[u][idx].reverse;

            residual[u][idx].capacity -= flow;

            // rev edge find
            for(long long j=0; j<residual[v].size(); j++){
                if(residual[v][j].to == u ){
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

int main(){

    long long n , m;
    cin >> n >> m;

    vector<vector<Edge>> adj(n);
    vector<pair<pair<long long,long long>, pair<long long,long long>>> seq;

    for(long long i=0; i<m; i++){
        long long u,v,c;
        cin >> u >> v >> c;
        adj[u-1].push_back({v-1, c, false});
        adj[v-1].push_back({u-1,c, false});
    }

    
    long long ans = ford_fulkerson(adj, 0, n-1, n);
    cout << ans << endl;
    
}