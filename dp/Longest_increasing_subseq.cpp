#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> a = {10, 22, 9, 33, 21, 50, 41, 60};
	int n = a.size();
	vector<int> dp(n, 1); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << endl;
}
