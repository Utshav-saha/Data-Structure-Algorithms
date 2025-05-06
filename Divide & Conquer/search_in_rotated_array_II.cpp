#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool search(vector<int>& nums, int target) {
            int low = 0;
            int high = nums.size() - 1;

            while(low <= high){
                int mid = (low+high) / 2;

                if(nums[mid] == target) return true;

                // Extra Case
                if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                    low += 1;
                    high -= 1;
                    continue;
                }

                // left sorted
                if(nums[low] <= nums[mid]){
                    if(nums[low] <= target && target <= nums[mid]){
                        high = mid-1;
                    }
                    else low = mid+1;
                }
                
                //right sorted
                else{
                    if(nums[mid] <= target && target <= nums[high]){
                    low = mid + 1;
                    }
                    else high = mid -1;
                }
                
                
            }
            return false;
        }
    };