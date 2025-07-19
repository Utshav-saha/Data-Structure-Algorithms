#include <bits/stdc++.h>
using namespace std;

int find_peak(vector <int> &arr, int low , int high){
    if(low > high) return -1;

    int mid = (low + high) / 2;

    if((mid == 0 || arr[mid] > arr[mid-1]) && (mid == arr.size()-1 || arr[mid] > arr[mid+1])) return arr[mid];

    else if(arr[mid+1] > arr[mid]) return find_peak(arr, mid+1, high);
    else return find_peak(arr, low, mid-1);
}

int main(){
    vector <int> v = {8,9,10,2,5,6};
    cout << find_peak(v, 0 , v.size()-1) << endl;
}