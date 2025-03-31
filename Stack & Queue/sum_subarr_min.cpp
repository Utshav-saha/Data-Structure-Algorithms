#include<bits/stdc++.h>
using namespace std;

vector<int> nse(vector<int> &arr) {   
    int n = arr.size();
    vector<int> nse(n, -1); 
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();  
        st.push(i);
    }

    return nse;
}

vector<int> psee(vector<int> &arr) {
    int n = arr.size();
    vector<int> pse(n, -1); 
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top(); 
        st.push(i);
    }

    return pse;
}

int sum(vector<int> &arr) {
    vector<int> nse_result = nse(arr);
    vector<int> pse_result = psee(arr);

    int total = 0;
    long int mod = (int)(1e9 + 7);  

    for (int i = 0; i < arr.size(); i++) {
        int left = i - pse_result[i];
        int right = nse_result[i] - i;

        total = (total + (right * left * 1LL * arr[i]) % mod) % mod;
    }
    return total;
}