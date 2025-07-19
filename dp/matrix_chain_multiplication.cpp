#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<int> A = {10, 20, 30, 40, 50};  // dimensions: 4 matrices
    int dp[n][n];

    // initialize all to 0 or INT_MAX appropriately
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = 0;

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int cost = A[i - 1] * A[k] * A[j] + dp[i][k] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[1][n - 1] << endl;
    return 0;
}
