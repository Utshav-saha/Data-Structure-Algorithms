// Codeforces - String Problem

#include <bits/stdc++.h>
using namespace std;


const long long INF = 1e15; 

void floydWarshall(vector<vector<long long>> &dist) {
    long long V = dist.size();
    
    for (long long k = 0; k < V; k++) {
        for (long long i = 0; i < V; i++) {
            for (long long j = 0; j < V; j++) {
                if(dist[i][k] != INF && dist[k][j]!= INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main(){
    string in, out;
    cin >> in >> out;
    
    vector<vector<long long>> dist(26, vector<long long>(26, INF));

    for(long long i=0; i<26; i++){
        dist[i][i] = 0;
    }

    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        char x, y;
        long long w;
        cin >> x >> y >> w;
        dist[x-'a'][y-'a'] = min(dist[x-'a'][y-'a'], w);
    }
    
    floydWarshall(dist);

    long long cost = 0;
    string res = "";

    if(in.length() != out.length()){
        cout << -1 << endl;
        return 0;
    }
    else{
        for(int i=0; i<in.length(); i++){
            if(in[i] == out[i]){
                res += in[i];
                continue;
            }

            char letter1 = in[i];
            char letter2 = out[i];
            
            long long minc = INF;
            char best = '.';

            for(char c='a'; c<='z'; c++){
                if(dist[letter1 - 'a'][c - 'a'] != INF && dist[letter2 - 'a'][c - 'a'] != INF) {
                    long long curr_cost = dist[letter1 - 'a'][c - 'a'] + dist[letter2 - 'a'][c - 'a'];
                    if(curr_cost < minc){
                        minc = curr_cost;
                        best = c;
                    }
                }
            }

            if(minc == INF){
                cout << -1 << endl;
                return 0;
            }
            else{
                cost += minc;
                res += best;
            }
        }
    }
    cout << cost << endl;
    cout << res << endl;
}