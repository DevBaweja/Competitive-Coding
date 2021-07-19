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

void rearrange(Node *root)
{
    Node *odd = root;
    if (!odd || !odd->next || !odd->next->next)
        return;

    Node *even = odd->next;
    odd->next = even->next;
    odd = odd->next;
    even->next = NULL;

    while (odd && odd->next)
    {
        Node *temp = odd->next->next;
        odd->next->next = even;
        even = odd->next;
        odd->next = temp;

        if (temp)
            odd = temp;
    }
    odd->next = even;
}