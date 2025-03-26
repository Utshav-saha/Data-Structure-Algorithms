#include<bits/stdc++.h>
using namespace std;

class Q {
    public:
        
        stack<int> s1, s2;
        
        void push(int x) {

            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);

            while(s2.size())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
        
        int pop() {
            int el = s1.top();
            s1.pop();
            return el;
        }
        
       
        int peek() {
            return s1.top();
        }
        
        bool empty() {
            return s1.empty() && s2.empty();
        }
    };