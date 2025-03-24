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

Node * merge_2(Node * head1, Node * head2)
{
    Node * dummy = new Node(-1);
    Node * temp = dummy;

    Node * t1 = head1;
    Node * t2 = head2;

    while(t1 && t2)
    {
        if(t1->data < t2->data)
        {
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }

        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;           
        }
    }

    if(t1) temp->next = t1;
    if(t2) temp->next = t2;

    return dummy->next;
}