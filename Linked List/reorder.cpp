#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * prev = nullptr;
        ListNode * end = slow->next;
        slow->next = nullptr;

        while(end){
            ListNode * last = end->next;
            end->next = prev;
            prev = end;
            end = last;
        }

        end = prev;
        ListNode * start = head;


        while(end){
            ListNode * front1 = start->next;
            ListNode * front2 = end->next;

            start->next = end;
            start = front1;
            end->next = start;
            end = front2;
        }
        
        


    }
};