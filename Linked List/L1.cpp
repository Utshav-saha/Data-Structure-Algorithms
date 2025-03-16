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
    return -1; // Return -1 if the value is not found
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl; // Add a newline for better output formatting
}

Node* deletion_first(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;

}

int main()
{
    vector <int> v = {12, 2, 31, 4, 5};
    Node* head = convertArr2LL(v);
    print(head);
    head = deletion_first(head);
    print(head);

    return 0; // Add return statement
}