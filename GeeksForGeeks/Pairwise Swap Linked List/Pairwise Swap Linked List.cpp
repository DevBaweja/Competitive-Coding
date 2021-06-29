#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *pairWiseSwap(Node *head)
{

    if (!head || !head->next)
        return head;

    Node *curr = head->next, *prev = head, *next = NULL;
    head = curr;
    while (true)
    {
        next = curr->next;
        curr->next = prev;
        if (!next || !next->next)
        {
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        curr = prev->next;
    }
    return head;
}