#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;

void floydWarshall(vector<vector<vector<long long>>> &dist) {
    int n = dist.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                
                if (dist[i][k][0] != INF && dist[k][j][0] != INF) {
                    dist[i][j][0] = min(dist[i][j][0], dist[i][k][0] + dist[k][j][0]);
                }

                long long discount = INF;

                if (dist[i][k][1] != INF && dist[k][j][0] != INF) {
                    discount = min(discount, dist[i][k][1] + dist[k][j][0]);
                }

                if (dist[i][k][0] != INF && dist[k][j][1] != INF) {
                    discount = min(discount, dist[i][k][0] + dist[k][j][1]);
                }

                dist[i][j][1] = min(dist[i][j][1], discount);
            }
        }
    }
}

int main(){
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(n, vector<long long>(2, INF)));

    for(int i = 0; i < n; i++){
        dist[i][i][0] = 0;
        dist[i][i][1] = 0;
    }

    for(int i = 0; i < m; i++){
        int x, y;
        long long w;
        cin >> x >> y >> w;
        
        dist[x-1][y-1][0] = min(dist[x-1][y-1][0], w);
        dist[x-1][y-1][1] = min(dist[x-1][y-1][1], w / 2);

       
    }

    floydWarshall(dist);

    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;

        if(dist[a-1][b-1][1] == INF){
            cout << -1 << endl;
        }
        else{
            cout << dist[a-1][b-1][1] << endl;
        } 
    }
}