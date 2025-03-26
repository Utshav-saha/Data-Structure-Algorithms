#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

class Q{

    Node * start = NULL;
    Node * end = NULL;
    int size = 0;

    public:
    void push(int x)
    {
        Node * temp = new Node(x);

        if(start == NULL)
        {
            start = temp;
            end = temp;
        }

        else
        {
             end->next = temp;
             end = temp;
        }

        size++;

    }

    int len()
    {
        return size;
    }

    void pop()
    {
        if(start == NULL) cout << "faka";

        Node * temp = start;
        start = start->next;

        if (start == NULL) {
            end = NULL;
        }

        delete(temp);
        size -- ;
    }

    int top()
    {
        if(start == NULL) cout << "faka";
        return start->data;
    }
};

int main() {
    Q q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.top() << endl; 
    cout << "Queue size: " << q.len() << endl;

    q.pop();
    cout << "Front element after pop: " << q.top() << endl; 
    cout << "Queue size after pop: " << q.len() << endl; 

    return 0;
}