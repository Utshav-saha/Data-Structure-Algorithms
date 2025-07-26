#include <bits/stdc++.h>
using namespace std;

struct Job {
    int start, finish, value;
};

bool comp(Job a, Job b) {
    return a.finish < b.finish;
}

int weightedIntervalScheduling(vector<Job>& jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    
    vector<int> dp(n);
    dp[0] = jobs[0].value;

    for (int i = 1; i < n; i++) {
        dp[i] = jobs[i].value;
        for (int j = 0; j < i; j++) {
            if (jobs[j].finish <= jobs[i].start) {
                dp[i] = max(dp[i], jobs[i].value + dp[j]);
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}
