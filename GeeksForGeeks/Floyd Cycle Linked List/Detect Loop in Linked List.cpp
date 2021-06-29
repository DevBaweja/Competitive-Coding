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
/*
    bool detectLoop(Node* head)
    {
        set<Node *> s;
        Node *temp = head;
        while (temp)
        {
            if (s.find(temp) != s.end())
                return true;
            s.insert(temp);
            temp = temp->next;
        }
        return false;
    }
*/

/*
    bool detectLoop(Node* head){
        Node *slow = head, *fast = head;
        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
*/

bool detectLoop(Node *head)
{
    Node *acc = new Node(-1);
    Node *temp = head;
    while (temp)
    {
        if (temp->next == acc)
            return true;
        Node *next = temp->next;
        temp->next = acc;
        temp = next;
    }
    return false;
}