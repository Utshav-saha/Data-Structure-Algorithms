#include <bits/stdc++.h>
using namespace std;

int max_triplet(vector <int> &v , int low, int high){
    if(high - low + 1 < 3) return -1;
    if(high - low + 1 == 3) return v[low]+v[low+1]+v[low+2];

    int mid = (low + high) / 2;

    int left = max_triplet(v, low , mid);
    int right = max_triplet(v, mid+1, high);

    int cross1 = 0;
    int cross2 = 0;

    if((mid-1) >= 0 && (mid+1) < v.size()) cross1 = v[mid-1] + v[mid] + v[mid+1];
    if((mid+1) < v.size() && (mid+2) < v.size()) cross2 = v[mid] + v[mid+1] + v[mid+2];

    return max({left, right, cross1, cross2});
}

int main(){
    vector <int> v = {3 ,-1, 2, 10, -12, 14, -4, 6, -8};
    cout << max_triplet(v, 0, v.size()-1);
}