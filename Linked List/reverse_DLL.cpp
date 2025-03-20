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

    Node* arr2Dll(vector <int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node* prev = head;

        for(int i=1; i< arr.size(); i++)
        {
            Node * temp = new Node(arr[i], nullptr, prev);
            prev->next = temp;
            prev = temp;
        }

        return head;
    }



    void print(Node* head){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl; 
    }


Node *reverseList(Node *head) {
    Node *last = NULL;
    Node *current = head;

    if(head == NULL || head->next == NULL) return head;

    while(current) {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
}

int main()
{
    vector <int> arr = {1,2,3,4};

        Node* head = arr2Dll(arr);
        print(head);

        head = reverseList(head);
        print(head);
}