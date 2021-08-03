#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Hashing
void removeLoop(Node *head)
{
    unordered_set<Node *> s;
    Node *temp = head;
    while (temp && temp->next)
    {
        if (s.find(temp->next) != s.end())
        {
            temp->next = NULL;
            return;
        }
        s.insert(temp);
        temp = temp->next;
    }
}

// Two Pointers
void eliminateLoop(Node *loop, Node *head)
{
    Node *p1 = loop;
    Node *p2 = loop;

    int count = 1;
    while (p2->next != p1)
    {
        count++;
        p2 = p2->next;
    }
    p1 = head;
    p2 = head;
    for (int i = 0; i < count; i++)
        p2 = p2->next;
    while (p1 != p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    while (p2->next != p1)
        p2 = p2->next;
    p2->next = NULL;
}

void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            eliminateLoop(slow, head);
            return;
        }
    }
}

// Two Pointers Optimized
void eliminateLoop(Node *loop, Node *head)
{
    Node *p1 = loop;
    Node *p2 = head;
    if (p1 == p2)
    {
        while (p1->next != p2)
            p1 = p1->next;
    }
    else
    {
        while (p1->next != p2->next)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    p1->next = NULL;
}

void removeLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (slow && fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            eliminateLoop(slow, head);
            return;
        }
    }
}