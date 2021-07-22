#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

node *reverse(node *root, int k)
{
    if (!root || k == 1)
        return root;

    node *curr = root;
    node *prev = NULL;
    node *next = NULL;
    int count = 0;

    while (curr && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next)
        root->next = reverse(next, k);

    return prev;
}
