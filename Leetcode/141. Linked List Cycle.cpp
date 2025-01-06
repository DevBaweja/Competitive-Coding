#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (!head)
        return false;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

bool hasCycle(ListNode *head) {
    if(!head) return false;
    ListNode *slow = head, *fast = head;
    do{ 
        fast = fast -> next;
        if(fast) {
            fast = fast->next;
            slow = slow->next;
        }
    } while(fast != NULL && fast != slow);
    
    return fast != NULL;
}