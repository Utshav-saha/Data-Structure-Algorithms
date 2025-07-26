#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int knapsack(vector<int>& wt, vector<int>& val, int n, int maxWeight) {
        vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

        // Base case: fill first row for all weights
        for (int w = wt[0]; w <= maxWeight; w++) {
            dp[0][w] = (w / wt[0]) * val[0];  // Repeatedly take item 0
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= maxWeight; j++) {
                int notTake = dp[i - 1][j];
                int take = INT_MIN;
                if (wt[i] <= j) {
                    take = val[i] + dp[i][j - wt[i]];  // here is the change , reuse allowed
                }
                dp[i][j] = max(take, notTake);
            }
        }

        return dp[n - 1][maxWeight];
    }
};
