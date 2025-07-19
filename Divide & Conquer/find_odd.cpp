#include <bits/stdc++.h>
using namespace std;


int findOdd(vector<int>& arr) {
    int low = 0, high = arr.size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (mid % 2 == 1) mid--; 

        if (arr[mid] == arr[mid + 1]) {
            low = mid + 2;  
        } else {
            high = mid;     
        }
    }

    return arr[low];  

}
