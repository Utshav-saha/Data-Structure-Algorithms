#include <iostream>
#include <string>
using namespace std;

class InvertedSubString {
private:
    string s;

public:
    InvertedSubString(string s) { this->s = s; } //constructor

    int merge(int l, int r, string s) {

        int i, j, mid, count = 0;
        mid = (l + r) / 2;

        j = mid;
        while(j > l){
            if(s[j - 1] - s[j] == 1) j--;
            else break;
        }
        int x = mid - j + 1;

        i = mid;
        while(i < r){
            if(s[i] - s[i + 1] == 1) i++;
            else break;
        }
        int y = i - mid;

        return x*y;
    }

    int divide(int l, int r, string s){
        if(l == r) return 0;
        int mid = (l+r)/2;
        int count1 = divide(l, mid, s);
        int count2 = divide(mid+1, r, s);
        int count3 = merge(l, r, s);
        return count1 + count2 + count3;
    }

    void print() {
        int count = divide(0, s.size() - 1, s);
        cout << count << endl;
    }
};

int main(){

    string s = "abdcba";
    InvertedSubString obj(s);
    obj.print();
}