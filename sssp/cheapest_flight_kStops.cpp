// leetcode - 787. Cheapest Flights Within K Stops

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n,1e8);
        vector<int> prev(n,1e8);
        prev[src] = 0;
        dist[src] = 0;

        for(int i =0; i <= k; i++){
            for(vector<int> flight : flights){
                int from = flight[0];
                int to = flight[1];
                int price = flight[2];

                if(prev[from] != 1e8 && prev[from]+ price < dist[to]){
                    dist[to] = prev[from] + price ; 
                }
            }
            prev = dist;
        }

        if(dist[dst] == 1e8) return -1;
        else return dist[dst];
        
    }
};