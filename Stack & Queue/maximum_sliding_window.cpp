#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    
            int n = arr.size();
            vector<int> results;
            deque<int> dq(k);
    
            for(int i = 0; i < k; i++) {
            
                while(!dq.empty() && arr[i] >= arr[dq.back()])
                    dq.pop_back();
                    dq.push_back(i);
            }
            for(int i = k; i < n; i++) {
                results.push_back(arr[dq.front()]);
                
                while(!dq.empty() && dq.front() <= i - k)
                    dq.pop_front();
                
                while(!dq.empty() && arr[i] >= arr[dq.back()])
                    dq.pop_back();
                
                dq.push_back(i);
            }
            results.push_back(arr[dq.front()]);
            return results;
        }
        
    };