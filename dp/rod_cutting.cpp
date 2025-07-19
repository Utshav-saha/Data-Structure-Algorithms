#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 9;
    vector <int> prices = {1,5,8,9,10,17,20,24,30};
    vector <int> prev(n+1, 0);
    vector<int> cut(n + 1, 0);

    for(int i=0; i<= n; i++){
        prev[i] = prices[0] * i;
        cut[i] = 1; 
    }

    for(int i = 1; i<n; i++){
        int rodlen = i+1;

        for(int j = rodlen; j<=n; j++){
            int not_take = 0 + prev[j];
            int take = prices[i] + prev[j - rodlen];

            if (take > prev[j]) {
                prev[j] = take;
                cut[j] = rodlen;  // record the rod length used
            }
        }
    }

    /*CLRS
    
    for(j = 1, j<=n ; j++){
        q = INT_MIN;
        for(int i=0; i<=j ; i++){
            if(q < prices[i] + prev[j-i]){
                q = prices[i] + prev[j-i];
                cut[j] = i;
            }
        }
        prev[j] = q;
    
    }
    */

    // Print max price
    cout << "Max price: " << prev[5] << endl;

    // Print cuts used
    cout << "Cuts used: ";
    int length = 5;
    while (length > 0) {
        cout << cut[length] << " ";
        length -= cut[length];
    }
}