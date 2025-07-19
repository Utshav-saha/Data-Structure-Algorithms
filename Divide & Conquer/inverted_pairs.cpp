#include <bits/stdc++.h>
using namespace std;

int inverted_pairs(const string &s, int l, int r) {
    if (r - l +1 < 2) return 0;

    int mid = (l + r) / 2;

    int left = inverted_pairs(s, l, mid);
    int right = inverted_pairs(s, mid+1, r);

    int cross = 0;
    if (s[mid] > s[mid + 1]) {
        cross = 1;
    
    }

    return left + right + cross;
}
int main(){
    string s = "abdcbabxawer";
    cout << inverted_pairs(s, 0 , s.size()-1) << endl;
}