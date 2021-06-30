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

Node *deleteK(Node *head, int k)
{
    if (!head || k == 0)
        return head;
    if (k == 1)
        return NULL;
    Node *temp = head;
    Node *prev = temp, *cur = temp->next;
    int count = 1;
    while (cur)
    {
        count++;
        count %= k;
        if (!count)
            prev->next = cur->next;
        prev = cur;
        cur = cur->next;
    }
    return temp;
}