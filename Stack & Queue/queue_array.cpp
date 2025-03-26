#include<bits/stdc++.h>
using namespace std;

class Q{

    public:
    int q[999];
    int size = 0;
    int start = -1;
    int end = -1;

    void push(int x)
    {
        if(size == 999) cout << "Jayga nai fat";

        if(size == 0){
            start = 0;
            end = 0;
        }

        else end = (end+1) % 999;

        q[end] = x;
        size++;
    }

    int pop(){
        if(size == 0)
        {
            cout << " faka ";
        }

        int el = q[start];

        if(size == 1)
        {
        start = -1;
        end = -1;
        }

        else
        {
        start = (start-1)%999;
        }

        size --;
        return el;

    }

    int top()
    {   
        if(size == 0)
        {
            cout << " faka ";
        }
        return q[start];
    }

    int len()
    {
        return size;
    }

};

int main() {
    Q q;
    
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Top element: " << q.top() << endl; // Should print 10
    cout << "Queue length: " << q.len() << endl; // Should print 3

    cout << "Pop element: " << q.pop() << endl; // Should print 10
    cout << "Queue length after pop: " << q.len() << endl; // Should print 2

    return 0;
}