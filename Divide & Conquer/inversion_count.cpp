#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, int&count){
    
    vector <int> ds;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(arr[left] < arr[right]){
            ds.push_back(arr[left++]);
        }
        else{
            ds.push_back(arr[right++]);
            count += mid - left +1;
        }
    }

    while(left <= mid){
        ds.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        ds.push_back(arr[right]);
        right++;
    }

    for(int i= low; i<= high; i++){
        arr[i] = ds[i-low];
    }
}


void  count_inversions(vector<int> &arr, int low, int high, int &count){
    if (low >= high) return;

    int mid = (low+high)/2;
    count_inversions(arr,low, mid, count);
    count_inversions(arr, mid+1, high, count);
    merge(arr, low, mid, high , count);
}


int main()
{
    vector <int> arr = {2,4,1,3,5};

    int count = 0;
    count_inversions(arr, 0 , arr.size()-1, count);

    cout << count << endl;
}