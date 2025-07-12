#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    void push(int val)
    {
        size++;
        int idx = size;

        arr[idx] = val;

        while (idx > 1)
        {
            int parent = idx / 2;
            if (arr[parent] < arr[idx])
            {
                swap(arr[parent], arr[idx]);
                idx = parent;
            }

            else
                return;
        }
    }

    void pop()
    {
        if (!size)
            return;

        arr[1] = arr[size];
        size--;

        int idx = 1;
        while (true)
        {
            int Lchild = 2 * idx;
            int Rchild = 2 * idx + 1;
            int largest = idx;

            if (Lchild <= size && arr[Lchild] > arr[largest])
                largest = Lchild;
            if (Rchild <= size && arr[Rchild] > arr[largest])
                largest = Rchild;

            if (largest != idx)
            {
                swap(arr[idx], arr[largest]);
                idx = largest;
            }
            else
            {
                break;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n , int idx){

        int Lchild = 2 * idx;
            int Rchild = 2 * idx + 1;
            int largest = idx;

            if (Lchild <= n && arr[Lchild] > arr[largest])
                largest = Lchild;
            if (Rchild <= n && arr[Rchild] > arr[largest])
                largest = Rchild;

            if (largest != idx)
            {
                swap(arr[idx], arr[largest]);
                idx = largest;

                heapify(arr, n , idx);
            }

    }

void heapsort(int arr[], int n){

    int size = n;
    while(size > 1){
        swap(arr[size], arr[1]);
        size --;

        heapify(arr, size, 1 );
    }
}

int main()
{

    // Suppose we are taking a Max-Heap
    heap h;
    h.push(60);
    h.push(50);
    h.push(40);
    h.push(30);
    h.push(20);
    h.push(55);
    h.push(70);

    //h.print();

    h.pop();
    //h.print();

    // int arr[6] = {-1, 54, 53, 55, 52, 50};
    // int n = 5;

    // for(int i=n/2; i>=1; i--){
    //     heapify(arr, 6 , i);
    // }

    // cout << " After heapify: ";
    // for(int i=1; i<=n; i++){
    //     cout << arr[i] << " ";
    // }


    int arr[6] = {-1, 70, 60, 55, 45, 50};
    heapsort(arr, 5);

    cout << " After Sorting: ";
    for(int i=1; i<=5; i++){
        cout << arr[i] << " ";
    }
}