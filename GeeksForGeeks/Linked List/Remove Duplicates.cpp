#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *removeDuplicates(Node *head)
{
    if (!head)
        return head;
    set<int> s;
    Node *slow = head, *fast = head->next;
    s.insert(slow->data);
    while (fast)
    {
        if (s.find(fast->data) != s.end())
            slow->next = fast->next;
        else
        {
            s.insert(fast->data);
            slow = fast;
        }
        fast = fast->next;
    }
    return head;
}