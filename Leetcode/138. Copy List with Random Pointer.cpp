#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return head;
    unordered_map<Node *, Node *> m;

    Node *dummy = new Node(-1);
    Node *copy;
    copy = dummy;
    Node *temp;
    temp = head;
    while (temp)
    {
        copy->next = new Node(temp->val);
        copy = copy->next;
        m[temp] = copy;
        temp = temp->next;
    }

    copy = dummy;
    temp = head;
    while (temp)
    {
        copy->next->random = m[temp->random];
        copy = copy->next;
        temp = temp->next;
    }
    return dummy->next;
}