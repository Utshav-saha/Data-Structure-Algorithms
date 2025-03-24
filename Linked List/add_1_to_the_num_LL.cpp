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

int helper(Node *temp) {
  
    if (temp == nullptr) {
        return 1;
    }

    int carry = helper(temp->next);

    temp->data = temp->data + carry;

    if(temp->data < 10) return 0;
    else{
        temp->data = 0;
        return 1;
    }
}

Node *addOne(Node *head) {
  
    int final_carry = helper(head);

    if (final_carry) {
        Node *newNode = new Node(final_carry);

        newNode->next = head;
        return newNode; 
    }

    return head;
}