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

int length(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

int search(Node* head, int val){
    Node* temp = head;
    int count = 0;
    while(temp){
        if(temp->data == val){
            return count;
        }
        count++;
        temp = temp->next;
    }
    return 0;
}

int main()
{
    vector <int> v = {12, 2, 31, 4, 5};
    Node* head = convertArr2LL(v);

    // Traversal

    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }

}