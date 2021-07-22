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

// Reverse
ListNode *addNode(ListNode *temp, int val)
{
    if (!temp)
    {
        temp = new ListNode(val);
        return temp;
    }

    ListNode *t = new ListNode(val);
    t->next = temp;
    return t;
}

ListNode *reverse(ListNode *temp)
{
    ListNode *cur = temp;
    ListNode *prev = NULL, *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *temp1 = l1, *temp2 = l2;
    ListNode *temp = NULL;
    while (temp1 || temp2)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if (temp2)
        {
            sum += temp2->val;
            temp2 = temp2->next;
        }
        carry = sum / 10;
        temp = addNode(temp, sum % 10);
    }
    if (carry)
        temp = addNode(temp, carry);
    return reverse(temp);
}

// Using Dummy Node
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    ListNode *temp1 = l1, *temp2 = l2;
    ListNode *dummy = new ListNode(0);
    ListNode *temp = dummy;
    while (temp1 || temp2)
    {
        int sum = carry;
        if (temp1)
        {
            sum += temp1->val;
            temp1 = temp1->next;
        }
        if (temp2)
        {
            sum += temp2->val;
            temp2 = temp2->next;
        }
        carry = sum / 10;
        temp->next = new ListNode(sum % 10);
        temp = temp->next;
    }
    if (carry)
        temp->next = new ListNode(carry);
    return dummy->next;
}