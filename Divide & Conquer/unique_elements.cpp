#include <bits/stdc++.h>
using namespace std;

int countUnique(const vector<int>& arr, int l, int r) {
    if (l == r) return 1;

    int mid = (l + r) / 2;

    int left = countUnique(arr, l, mid);
    int right = countUnique(arr, mid+1, r);

    if (arr[mid] == arr[mid + 1]) {
        return left + right - 1;
    } else {
        return left + right;
    }
}
int main(){
    vector <int> arr = {1,2,2,3,5};
    cout << countUnique(arr, 0 , arr.size()-1) << endl;
}