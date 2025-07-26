#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> nextGreaterElements(vector<int>& nums) {
            int n = nums.size();
            vector<int> result(n); 
            stack<int> s; 
            
            for(int i = 2*n - 1; i >= 0; i--) {
                while(!s.empty() && nums[s.top()] <= nums[i % n]) {
                    s.pop();
                }
                
                result[i % n] = (s.empty() ? -1 : nums[s.top()]);
                s.push(i % n);
            }
            return result;
        }
    };