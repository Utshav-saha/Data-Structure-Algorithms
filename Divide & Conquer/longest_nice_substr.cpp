#include <iostream>
#include <string>
#include <vector>
using namespace std;

string helper(const string& s, int l, int r) {
    if (l > r) return "";

    vector<int> lower(26, 0), upper(26, 0);

    for (int i = l; i <= r; i++) {
        char c = s[i];
        if (islower(c)) lower[c - 'a']++;
        else if (isupper(c)) upper[c - 'A']++;
    }

    for (int i = l; i <= r; i++) {
        char c = s[i];
        int idx = tolower(c) - 'a';
        if ((islower(c) && upper[idx] == 0) || (isupper(c) && lower[idx] == 0)) {
            string left = helper(s, l, i - 1);
            string right = helper(s, i + 1, r);
            return (left.length() >= right.length()) ? left : right;
        }
    }

    return s.substr(l, r - l + 1);
}

string longestNiceSubstring(const string& s) {
    return helper(s, 0, s.length() - 1);
}

int main() {
    string s = "xyYAAYaxyXZa";
    cout << longestNiceSubstring(s) << endl; 
}