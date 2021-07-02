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

Node *addNode(Node *head, int data)
{
    if (!head)
        return new Node(data);
    if (head->data == data)
        return head;
    Node *temp = new Node(data);
    temp->next = head;
    return temp;
}

struct Node *makeUnion(struct Node *head1, struct Node *head2)
{
    vector<int> s1, s2;
    while (head1)
    {
        s1.push_back(head1->data);
        head1 = head1->next;
    }
    while (head2)
    {
        s2.push_back(head2->data);
        head2 = head2->next;
    }

    sort(s1.begin(), s1.end(), greater<int>());
    sort(s2.begin(), s2.end(), greater<int>());

    int i = 0, j = 0;
    Node *temp = NULL;

    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] >= s2[j])
            temp = addNode(temp, s1[i++]);
        else
            temp = addNode(temp, s2[j++]);
    }

    while (i < s1.size())
        temp = addNode(temp, s1[i++]);
    while (j < s2.size())
        temp = addNode(temp, s2[j++]);

    return temp;
}
