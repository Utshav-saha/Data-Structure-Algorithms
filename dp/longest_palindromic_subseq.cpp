#include <bits/stdc++.h>
using namespace std;


int lps(const string& s, int low, int high, vector<vector<int>> &memo) {

    // Base case
    if(low > high) return 0;
  
    // If there is only 1 character
    if (low == high)
        return 1;

    // If the value is already calculated
    if(memo[low][high] != -1) 
        return memo[low][high];

    // If the first and last characters match
    if (s[low] == s[high])
        return memo[low][high] = 
                lps(s, low + 1, high - 1, memo) + 2;

    // If the first and last characters do not match
    return memo[low][high] = 
      			max(lps(s, low, high - 1, memo),
                         lps(s, low + 1, high, memo));
}

int longestPalinSubseq(string &s) {

    // create memoization table
    vector<vector<int>> memo(s.size(), 
                    vector<int>(s.size(), -1));
    return lps(s, 0, s.size() - 1, memo);
}

int main() {
    string s = "bbabcbcab";
    cout << longestPalinSubseq(s);
    return 0;
}