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

Node * sum_num(Node * head1, Node * head2)
{
    Node * l1 = head1;
    Node * l2 = head2;
    
    int carry = 0;

    Node * dummy = new Node(-1);
    Node * curr = dummy;

    while(l1 || l2 || carry) {

        int sum = carry;

        if(l1) {
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2) {
            sum += l2->data;
            l2 = l2->next;
        }
        curr->next = new Node(sum % 10);
        carry = sum / 10;
        curr = curr->next;
    }
    return dummy->next;
}