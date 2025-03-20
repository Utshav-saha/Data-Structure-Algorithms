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

    Node * delete_head(Node * head)
    {
        if(head == NULL || head->next == NULL) return NULL;

        Node * prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;

        delete(prev);
        return head;

    }

    Node * delete_tail(Node * head)
    {
        if(head == NULL || head->next == NULL) return NULL;

        Node * tail = head;
        while(tail->next)
        {
            tail = tail->next;

        }
        Node * prev = tail->back;
        prev->next = nullptr;
        tail->back = nullptr;

        delete tail;

        return head;
    }

    Node * remove_kth(Node * head , int k)
    {
        if( head == NULL) return NULL;

        int count = 0;
        Node * temp = head;
        while(temp)
        {
            count++;
            if(count == k) break;

            temp = temp->next;
        }
        Node * prev = temp->back;
        Node * front = temp->next;

        if(prev == NULL && front == NULL)
        {
            delete temp;
            return NULL;
        }

        else if(prev == NULL) return delete_head(head);
        else if(front == NULL) return delete_tail(head);

        else{
            prev->next = front;
            front->back = prev;
            temp->next = NULL;
            temp->back = NULL;

            delete(temp);
            return head;
        }
    }
    Node * b4head(Node * head , int val)
    {
        Node * nhead = new Node(val, head , nullptr);
        head->back = nhead;

        return nhead;
    }

    Node * b4tail(Node * head , int val)
    {
        Node * temp = head;
        Node * prev = nullptr;

        if(head->next == NULL)
        {
            return b4head(head, val);
        }
        
        while(temp->next)
        {
            prev = temp;
            temp = temp->next;
        }

        Node * el = new Node(val,temp,prev);
        prev->next = el;
        temp->back = el;

        return head;
    }

    Node * b4kth(Node * head , int val , int k)
    {
        Node * temp = head;
        if(k==1)
        {
            return b4head(head, val);
        }

        int count = 0;
        
        while(temp->next)
        {   
            count++;
            if(count == k) break;

            temp = temp->next;
        }

        Node * prev = temp->back;
        Node * el = new Node(val,temp,prev);
        prev->next = el;
        temp->back = el;

        return head;
    }
    

    int main()
    {
        vector <int> arr = {1,2,3,4};

        Node* head = arr2Dll(arr);
        print(head);

        head = b4kth(head, 19, 3);
        print(head);

    }
