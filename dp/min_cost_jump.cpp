#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev = cost[1];
        int prev2 = cost[0];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev, prev2);
            prev2 = prev;
            prev = curr;
        }
        return min(prev, prev2);
    }
};