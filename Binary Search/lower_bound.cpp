#include<bits/stdc++.h>
using namespace std;

// Same code for insert position 

int lower_bound(vector <int> &nums, int target){

    int low = 0;
    int high = nums.size() -1;

    int ind = nums.size();

    while(low <= high){

        int mid = (low+high)/2;

        if(nums[mid] >= target) {
            ind = min(mid, ind);
            high = mid -1;
        }

        else{
            low = mid + 1;
        }
    }

    return ind;
}