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

// Hashing
bool detectLoop(Node *head)
{
    unordered_set<Node *> s;
    while (head)
    {
        s.insert(head);
        if (s.find(head->next) != s.end())
            return true;
        head = head->next;
    }
    return false;
}

// Cycle
bool detectLoop(Node *head)
{
    Node *slow, *fast;
    slow = head;
    fast = head;
    while (slow && fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return true;
    }
    return false;
}

// Visited
bool detectLoop(Node *head)
{
    Node *dummy = new Node(-1);
    Node *temp = head;
    while (temp)
    {
        Node *next = temp->next;
        if (next == dummy)
            return true;
        temp->next = dummy;
        temp = next;
    }
    return false;
}