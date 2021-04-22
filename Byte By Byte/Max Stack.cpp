#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *old_max;

    Node(int data)
    {
        this->data = data;
        next = NULL;
        old_max = NULL;
    }
};

struct Stack
{
    Node *head;
    Node *max;
    Stack()
    {
        head = NULL;
        max = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (!head)
            head = temp;
        else
        {
            temp->next = head;
            head = temp;
        }

        if (max == NULL || temp->data > max->data)
        {
            temp->old_max = max;
            max = temp;
        }
    }

    int pop()
    {
        Node *temp = head;
        head = head->next;
        if (temp->old_max)
            max = temp->old_max;
        return temp->data;
    }

    int get_max()
    {
        return max->data;
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s.pop() << " ";
    cout << s.pop() << " ";
    s.push(5);
    cout << s.pop() << " ";
    cout << s.get_max() << " ";
    return 0;
}