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

// Time - O(nk)
Node *rotate(Node *head, int k)
{
    while (k--)
    {
        Node *next = head->next;
        head->next = NULL;
        Node *cur = next;
        while (cur->next)
            cur = cur->next;
        cur->next = head;
        head = next;
    }
    return head;
}

// Time - O(n)
Node *rotate(Node *head, int k)
{
    Node *temp = head;
    k--;
    while (k--)
        temp = temp->next;
    Node *cur = temp->next;
    if (!cur)
        return head;
    Node *next = cur;
    temp->next = NULL;
    while (cur->next)
        cur = cur->next;
    cur->next = head;
    return next;
}