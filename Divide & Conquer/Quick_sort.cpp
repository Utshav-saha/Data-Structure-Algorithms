#include <bits/stdc++.h>
using namespace std;

int func(vector <int> &nums, int low , int high){

    int pivot = nums[low];
    int i = low ; 
    int j = high;

    while(i<j){
        while(nums[i] <= pivot && i <= high) i++;
        while(nums[j] >= pivot && j >= low) j--;

        if(i<j) swap(nums[i], nums[j]);
    }

    swap(nums[low] , nums[j]);
    return j;
}

void quick_sort(vector <int> &nums, int low , int high){
    if(low < high){
        int partition = func(nums, low, high);
        quick_sort(nums, low , partition -1);
        quick_sort(nums , partition + 1 , high);
    }
}