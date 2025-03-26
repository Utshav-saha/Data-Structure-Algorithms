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

class st{
    public:
    Node * top ;
    int size = 0;

    void push(int x)
    {
        Node * temp = new Node(x);
        temp->next = top;
        top = temp;
        size ++;
    }

    void pop()
    {
        Node * temp = top;
        top = top->next;
        delete(temp);
        size -- ;
    }

    int top_el()
    {
        return top->data;
    }

    int len()
    {
        return size;
    }
};

int main() {
    st s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top_el() << endl; // Should print 30
    cout << "Stack size: " << s.len() << endl; // Should print 3

    s.pop();
    cout << "Top element after pop: " << s.top_el() << endl; // Should print 20
    cout << "Stack size after pop: " << s.len() << endl; // Should print 2

    return 0;
}