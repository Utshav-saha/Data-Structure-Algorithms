#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(vector <int> &wt, vector<int> &val, int n , int maxWeight) {
        
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

        for(int w = wt[0]; w <= maxWeight; w++){
            dp[0][w] = val[0];
        }

        for( int i =1; i<n ; i++){
            for( int j = 0; j<= maxWeight; j++){
                int notTake = dp[i-1][j];

                int take = INT_MIN;
                if(wt[i] <= j){
                    take = val[i] + dp[i-1][j - wt[i]];
                }

                dp[i][j] = max(take, notTake);
                
            }
        }

        return dp[n-1][maxWeight];
    }
};