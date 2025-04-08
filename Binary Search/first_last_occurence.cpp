#include<bits/stdc++.h>
using namespace std;

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

int upper_bound(vector <int> &nums, int target){

    int low = 0;
    int high = nums.size() -1;

    int ind = nums.size();

    while(low <= high){

        int mid = (low+high)/2;

        if(nums[mid] > target) {
            ind = mid;
            high = mid -1;
        }

        else{
            low = mid + 1;
        }
    }

    return ind;
}

pair<int, int> first_last_occurence(vector<int> &nums, int x) {
    int lb = lower_bound(nums, x);
    int rb = upper_bound(nums, x) - 1; 

    if (lb < nums.size() && nums[lb] == x) {
        return {lb, rb};
    } else {
        return {-1, -1};
    }
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 3, 4, 5};
    int target = 2;

    pair<int, int> result = first_last_occurence(nums, target);

    if (result.first != -1) {
        cout << "First occurrence: " << result.first << endl;
        cout << "Last occurrence: " << result.second << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}