#include <bits/stdc++.h>
using namespace std;


void floydWarshall(vector<vector<long long>> &dist) {
    long long V = dist.size();

    
    for (long long k = 0; k < V; k++) {

        for (long long i = 0; i < V; i++) {

            
            for (long long j = 0; j < V; j++) {

                
                if(dist[i][k] != 1e8 && dist[k][j]!= 1e8)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){

    long long n , m , q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist(n, vector<long long>(n, 1e8));

    for(long long i=0;i<n;i++){
        dist[i][i] = 0;
    }

    for(long long i=0; i<m; i++){
        long long x , y,w;
        cin >> x >> y >> w;
        dist[x-1][y-1] = min(dist[x-1][y-1],w);
        dist[y-1][x-1] = dist[x-1][y-1];

    }

    floydWarshall(dist);

    for(long long i=0; i<q; i++){
        long long a, b;
        cin >> a >> b;

        if(dist[a-1][b-1] == 1e8){
            cout << -1 << endl;
        }
        else{
            cout << dist[a-1][b-1] << endl;
        } 

    }

}

