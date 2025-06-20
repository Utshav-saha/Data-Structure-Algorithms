#include<bits/stdc++.h>
using namespace std;

class st{
    public:
    int temp = -1;
    int arr[1000];

    public:
    void push(int x)
    {
        if(temp > 1000)
        {
            cout << "Size exceeded";
            return;
        }
        temp++;
        arr[temp] = x;
    }

    int top()
    {
        if(temp == -1) 
        {
            cout << "Stack is empty";
            return -1;
        }
        else return arr[temp];
    }

    void pop()
    {
        if(temp == -1) cout << "Stack is empty";
        else temp--;
    }

    int size()
    {
        return temp+1;
    }


};

int main()
{
st s;

s.push(10);
s.push(20);
s.push(30);

cout << "Top element: " << s.top() << endl;
cout << "Stack size: " << s.size() << endl;

s.pop();
cout << "Top element after pop: " << s.top() << endl;
cout << "Stack size after pop: " << s.size() << endl;

return 0;
}
