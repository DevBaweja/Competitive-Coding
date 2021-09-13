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

int intersectPoint(Node *head1, Node *head2)
{
    Node *temp1 = head1;
    while (temp1)
    {
        Node *temp2 = head2;
        while (temp2)
        {
            if (temp1 == temp2)
                return temp1->data;
            temp2 = temp2->next;
        }
        temp1->next;
    }
    return -1;
}

// Time- O(m+n)
// Space- O(m+n)
int intersectPoint(Node *head1, Node *head2)
{
    unordered_set<Node *> s;
    while (head1)
    {
        s.insert(head1);
        head1 = head1->next;
    }
    while (head2)
    {
        if (s.find(head2) != s.end())
            return head2->data;
        head2 = head2->next;
    }
    return -1;
}

// Time- O(n+m)
// Two Traversal
// Space- O(1)
int getCount(Node *head)
{
    int c = 0;
    while (head)
    {
        head = head->next;
        c++;
    }
    return c;
}

int getIntersection(Node *cur1, Node *cur2, int d)
{
    while (d--)
    {
        if (!cur1)
            return -1;
        cur1 = cur1->next;
    }

    while (cur1 && cur2)
    {
        if (cur1 == cur2)
            return cur1->data;
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return -1;
}

int intersectPoint(Node *head1, Node *head2)
{
    int c1 = getCount(head1), c2 = getCount(head2);

    int maxi = max(c1, c2);
    int res = -1;
    if (maxi == c1)
        res = getIntersection(head1, head2, c1 - c2);
    else
        res = getIntersection(head2, head1, c2 - c1);

    return res;
}