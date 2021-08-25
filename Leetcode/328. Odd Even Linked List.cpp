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

ListNode *oddEvenList(ListNode *head)
{
    if (!head || !head->next || !head->next->next)
        return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *todd = odd;
    ListNode *teven = even;
    while (teven && teven->next)
    {
        todd->next = todd->next->next;
        teven->next = teven->next->next;
        todd = todd->next;
        teven = teven->next;
    }
    todd->next = even;
    return odd;
}