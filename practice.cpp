#include <bits/stdc++.h>
using namespace std;

void insertion_sort(int nums[], int n){
    for(int i=1; i<n; i++){
        int j = i;
        while((nums[j-1] > nums[j]) && j>0){
            swap(nums[j], nums[j-1]);
            j--;
        }
    }
}

void merge(int arr1[] , int arr2[], int m , int n){

    int j = m+n-1;
    for(int i= j; i>=0; i--){
        if(arr1[i] != -1){
            arr1[j] = arr1[i];
            j--;
        }
    }

    j= n;
    int k = 0;

    for(int i=0; i<m+n; i++){
        if(arr1[j] < arr2[k]){
            arr1[i] = arr1[j];
            j++;
        }
        else{
            arr1[i] = arr2[k];
            k++;
        }
    }



}

int target_sum(int nums[], int n, int x){

    int i=0;
    int j = n-1;

    while(i<j){

        int sum = nums[i] + nums[j];
        if(sum == x) return true;

        if(sum < x){
            i++;
        }

        else j--;
    }

    return false;

}

int subarray_sum(int arr[], int n){
    int sum;
    int res = 0;

    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            if(sum > res) res = sum;
        }
    }

    return res;
}

void reverse(int arr[], int i , int j){
    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void left_shift(int arr[], int n , int k){

    k = k % n;

    reverse(arr, 0 , k-1);
    reverse(arr, k , n-1);
    reverse(arr, 0 , n-1);
}

void right_shift(int arr[], int n , int k){

    k = k % n;

    reverse(arr, n-k , n-1);
    reverse(arr, 0 , n-k-1);
    reverse(arr, 0 , n-1);
}
void squeeze(char arr[], int n){
    int count = 1;
    char letter = arr[0];
    int size = 0;

    for(int i=1; i<n; i++){
        if(arr[i] != letter){
            cout << letter << count;
            count = 1;
            letter = arr[i];
            size += 2;
        }
        else count++;
    }
    cout << letter << count;
    size +=2;
    cout << endl;

    if(size > n){
        for(int i=0; i<n; i++){
            cout << arr[i];
        }
    }
}

int main() {
    int nums1[] = {2, 8, -1, -1, -1, 13, -1, 15, 20};
    int nums2[] = {5, 7, 9, 25};

    int m = 5;
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d", subarray_sum(arr,n));


    // merge(nums1,nums2,m,n);

    // for(int i=0; i<m+n; i++){
    //     cout << nums1[i] << " ";
    // }
}