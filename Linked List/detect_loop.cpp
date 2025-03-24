#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data; 
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector < int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

bool detect_loop(Node * head)
{
    Node * slow = head;
    Node * fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast ) return true;
    }

    return false;
}

int main()
{
    vector <int> v = {12, 2, 31, 4, 5};
    Node* head = convertArr2LL(v);
    
    cout << detect_loop(head);
    return 0; 
}