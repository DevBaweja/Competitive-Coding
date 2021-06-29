#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

int getNthFromLast(Node *head, int n)
{

    Node *prev = head, *curr = head;
    n--;
    while (n--)
    {
        if (curr->next)
            curr = curr->next;
        else
            return -1;
    }

    while (curr->next != NULL)
    {
        curr = curr->next;
        prev = prev->next;
    }
    return prev->data;
}