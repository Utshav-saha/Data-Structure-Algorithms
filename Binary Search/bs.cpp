
#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int search(vector<int>& nums, int target) {
            
            int res = bs_iterative(nums, 0, nums.size()-1, target);
            return res;
        }

        int  bs_iterative(vector <int> &nums, int low, int high, int target){

            while(low <= high){

                int mid = (high+low)/2;

                if(nums[mid] == target) return mid;

                else if(nums[mid] < target) low = mid+1 ;
                else high = mid-1;

            }

            return -1;
        }

        int bs_recursive(vector <int> &nums, int low, int high , int target){

            if(low > high) return -1;

            int mid = (high + low)/2;

            if(nums[mid] == target) return mid;
            else if(target > nums[mid]) return bs_recursive(nums, mid+1, high, target);
            else return bs_recursive(nums, low, mid-1, target);

        }
    };