#include <bits/stdc++.h>
using namespace std;

int ways(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = ways(n - 1, dp) + ways(n - 2, dp);
    return dp[n];
}

int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);
    cout << ways(n, dp) << endl;
}