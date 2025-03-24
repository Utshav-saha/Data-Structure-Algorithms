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

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Add a newline for better output formatting
}

Node* odd_even(Node* head) {
    if (!head || !head->next) return head; 

    Node* odd = head;
    Node* even = head->next;
    Node* even_head = even;

    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_head; 
    return head;
}

int main()
{
    vector <int> v = {12, 2, 31, 4, 5};
    Node* head = convertArr2LL(v);
    print(head);
    head = odd_even(head);
    print(head);

    return 0; 
}