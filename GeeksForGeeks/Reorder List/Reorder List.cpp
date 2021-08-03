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
Node *findMiddle(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *reverse(Node *head)
{
    Node *cur = head;
    Node *prev = NULL, *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

Node *merge(Node *head, Node *middle)
{
    Node *first = head, *second = middle->next;
    middle->next = NULL;
    Node *dummy = new Node(-1);
    head = dummy;
    while (first || second)
    {
        if (first)
        {
            head->next = first;
            head = head->next;
            first = first->next;
        }
        if (second)
        {
            head->next = second;
            head = head->next;
            second = second->next;
        }
    }
    return dummy->next;
}

void reorderList(Node *head)
{
    Node *middle = findMiddle(head);
    middle->next = reverse(middle->next);
    head = merge(head, middle);
}