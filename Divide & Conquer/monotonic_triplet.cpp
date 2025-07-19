#include <bits/stdc++.h>
using namespace std;

int monotonic(vector <int> &v, int low, int high){
    if (high - low + 1 < 3) return -1;

    int mid = (low+high)/2;
    int left = monotonic(v, low, mid);

    if(left != -1) return left;
    if((mid-1)>=0 && (mid+1)< v.size()){
        if((v[mid-1] < v[mid] && v[mid] < v[mid+1]) || (v[mid-1] > v[mid] && v[mid] > v[mid+1])) return mid-1;

    }

    return monotonic(v, mid+1, high);
}

int main(){
    vector<int> v = {1,1,2,2,2,1,1};  
    int result = monotonic(v, 0, v.size() - 1);
    cout << result << endl;
}