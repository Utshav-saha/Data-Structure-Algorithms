// CODEFORCES: Greg and Graph

#include <bits/stdc++.h>
using namespace std;

int main() {
    

    int n;
    cin >> n;

    vector<vector<long long>> dist(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--; 
    }

    reverse(order.begin(), order.end());

    vector<long long> results;
    
    
    for (int k = 0; k < n; k++) {
        int pivot = order[k];

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][pivot] + dist[pivot][j]);
            }
        }

        
        long long sum = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                
                sum += dist[order[i]][order[j]];
            }
        }
        results.push_back(sum);
    }

    
    reverse(results.begin(), results.end());

    for (long long val : results) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}