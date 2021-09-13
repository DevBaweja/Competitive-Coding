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

// Two Traversal
Node *reverse(Node *head)
{
    Node *prev, *cur, *next;
    prev = NULL;
    cur = head;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int getNthFromLast(Node *head, int n)
{
    if (!head)
        return -1;
    Node *temp = reverse(head);
    n--;
    while (n--)
    {
        temp = temp->next;
        if (!temp)
            return -1;
    }
    return temp->data;
}

// Two Traversal
int getNthFromLast(Node *head, int n)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    int dist = count - n;
    if (dist < 0)
        return -1;
    temp = head;
    while (dist--)
        temp = temp->next;
    return temp->data;
}

// One Traversal
int getNthFromLast(Node *head, int n)
{
    Node *slow = head;
    Node *fast = head;
    while (n--)
    {
        if (!fast)
            return -1;
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}

// One Traversal
int getNthFromLast(Node *head, int n)
{
    if (!head)
        return -1;
    n--;
    Node *fast = head;
    while (n--)
    {
        fast = fast->next;
        if (!fast)
            return -1;
    }
    Node *slow = head;
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->data;
}