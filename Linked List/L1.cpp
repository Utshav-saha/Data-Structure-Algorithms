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

Node* delete_head(Node* head){
    if(head == NULL) return head;

    Node* temp = head;
    head = head->next;
    delete temp;
    return head;

}

Node* delete_tail(Node* head)
{
    if(head == NULL || head->next == NULL) return NULL;

    Node *temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return head;
}

Node* remove_k(Node* head, int k)
{
    if (head == NULL) return head;
    if(k == 1){
        Node * temp = head;
        head = head->next;

        free(temp);
        return head;

    }

    int count = 0;
    Node* temp = head;
    Node * prev = NULL;

    while (temp)
    {
        count ++;
        if(count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node * insert_head(Node* head, int val)
{
    Node * temp = new Node(val , head);
    return temp;
}

Node * insert_tail(Node*head, int val)
{
    if(head == NULL) return new Node(val);
    Node * temp = head;

    while(temp->next){
        temp = temp->next;
    }
    Node * newnode = new Node(val);
    temp-> next = newnode;
    return head;
}

Node * insert_k (Node * head , int val, int k)
{
    if(head == NULL)
    {
        if(k==1) return new Node(val);
        else return NULL;
    }

    if(k==1)
    {
        Node * temp = new Node(val , head);
        return temp;
    }

    int count = 0;
    Node * temp = head;

    while(temp)
    {
        count ++;
        if(count == k-1){
            Node * x = new Node(val);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;

}

Node * insert_before_val (Node * head , int el, int val)
{
    if(head == NULL)
    {
        return NULL;
    }

    if(head->data == val)
    {
        Node * temp = new Node(el , head);
        return temp;
    }

    
    Node * temp = head;

    while(temp->next)
    {
        
        if(temp->next->data == val){
            Node * x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }

    return head;

}
int main()
{
    vector <int> v = {12, 2, 31, 4, 5};
    Node* head = convertArr2LL(v);
    print(head);
    head = insert_before_val(head, 11,31);
    print(head);

    return 0; // Add return statement
}