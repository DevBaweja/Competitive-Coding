#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList() { head = NULL; }
    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    Node *rearrangeUsingContent(Node *root)
    {

        Node *temp;
        temp = root;
        vector<int> A;
        while (temp)
        {
            A.push_back(temp->data);
            temp = temp->next;
        }

        int n = A.size();
        temp = root;
        int index = 0;

        while (temp && temp->next)
        {
            temp->data = A[index];
            temp = temp->next;

            temp->data = A[n - index - 1];
            temp = temp->next;
            index++;
        }
        copy if (temp)
            temp->data = A[index];

        return root;
    }
};

int main()
{

    LinkedList ll1;
    // 1->2->3->4
    // 1->4->2->3
    ll1.push(4);
    ll1.push(3);
    ll1.push(2);
    ll1.push(1);

    ll1.head = ll1.rearrangeUsingContent(ll1.head);
    ll1.print();
    cout << "\n";

    LinkedList ll2;
    // 1->2->3->4->5
    // 1->5->2->4->3
    ll2.push(5);
    ll2.push(4);
    ll2.push(3);
    ll2.push(2);
    ll2.push(1);

    ll2.head = ll2.rearrangeUsingContent(ll2.head);
    ll2.print();
    cout << "\n";

    return 0;
}