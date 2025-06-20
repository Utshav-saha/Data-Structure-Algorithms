#include <bits/stdc++.h>
using namespace std;

vector <int> bfs(int v , vector <int> adj[]){
    vector<int> vis(v,0);
    vis[0] = 1;
    queue<int> q;
    q.push(0);

    vector<int> res;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        res.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] =1;
                q.push(it);
            }
        }
    }
    return res;

};