#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minimize_height(vector<int>& nums , int p) {
            
            sort(nums.begin(), nums.end());

            int big = nums[nums.size()-1] - p;
            int small = nums[0] + p;

            int diff = big -small;

            for(int i=1; i< nums.size(); i++){
                
                if(nums[i] - p < 0) continue;
                int mini = min(small, nums[i] - p);
                int maxi = max(big, nums[i-1]+p);

                diff = min(diff,maxi-mini);

                
            }
            return diff;
        }
    };