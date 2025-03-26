#include<bits/stdc++.h>
using namespace std;

class st {
    public:
        
        queue<int> q;
        
        void push(int x) {
            q.push(x);

            int size = q.size();
            for(int i = 1; i < size; i++) {
                q.push(q.front());
                q.pop();
            }
        }
        
        int pop() {
            int front = q.front();
            q.pop();
            return front;
        }
        
        int top() {
            return q.front();
        }
        
        bool empty() {
            return q.empty();
        }
    };