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

Node * remove_nth_from_end(Node * head , int n)
{
    Node * fast = head;
    Node * slow = head;

    for(int i=0; i<n; i++)
    {
        fast = fast->next;
    }

    if(fast == NULL) return head->next;

    while(fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }


    Node * del_node = slow->next;
    slow->next= slow->next->next;

    free(del_node);
    return head;

}