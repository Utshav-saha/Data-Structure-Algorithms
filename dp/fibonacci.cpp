#include <bits/stdc++.h>
using namespace std;

int memoization(int n, vector<int>& dp){
    if(n <= 1) return n;
    if(dp[n] != -1) return dp[n];
    dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
    return dp[n];
}

void tabular(int n, vector<int>& dp){
    dp[0] = 0; // prev2 = 0
    dp[1] = 1; // prev = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]; // cur = prev2 + prev

        // prev2 = prev;
        // prev = curr;           S.C ---> O(1)
    }
}

int main(){

    int n = 5;

    // vector<int> dp(n+1, -1); 
    // cout << memoization(n, dp) << endl;

    vector<int> dp(n+1, 0); 
    tabular(n, dp);
    cout << dp[n];
}