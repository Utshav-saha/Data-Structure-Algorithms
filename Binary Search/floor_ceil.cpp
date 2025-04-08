#include<bits/stdc++.h>
using namespace std;

int ceil(vector <int> &nums, int target){

    int low = 0;
    int high = nums.size() -1;

    int ans = -1;

    while(low <= high){

        int mid = (low+high)/2;

        if(nums[mid] >= target) {
            
            ans = nums[mid];
            high = mid -1;
        }

        else{
            low = mid + 1;
        }
    }

    return ans;
}

int floor(vector <int> &nums, int target){

    int low = 0;
    int high = nums.size() -1;

    int ans = -1;

    while(low <= high){

        int mid = (low+high)/2;

        if(nums[mid] < target) {
            
            ans = nums[mid];
            low = mid+1;
        }

        else{
            high = mid -1 ;
        }
    }

    return ans;
}