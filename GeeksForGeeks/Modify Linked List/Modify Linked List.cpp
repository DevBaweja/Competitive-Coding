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
Node *reverseList(Node *head)
{
    Node *cur = head, *prev = NULL, *next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void splitList(Node *head, Node *&front, Node *&back)
{
    Node *slow = head, *fast = head->next;
    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    front = head;
    back = slow->next;
    slow->next = NULL;
}

Node *concatList(Node *front, Node *back)
{
    Node *head = front;
    while (front->next)
        front = front->next;
    front->next = back;
    return head;
}

void modify(Node *front, Node *back)
{
    while (back)
    {
        int temp = back->data;
        back->data = front->data - temp;
        front->data = temp;
        front = front->next;
        back = back->next;
    }
}

Node *modifyTheList(Node *head)
{
    if (!head || head->next == NULL)
        return head;

    Node *front, *back;
    splitList(head, front, back);
    back = reverseList(back);
    modify(front, back);
    back = reverseList(back);
    head = concatList(front, back);
    return reverseList(head);
}