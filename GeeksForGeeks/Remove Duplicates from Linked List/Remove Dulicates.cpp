#include <iostream>
#include <set>
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

    Node *removeDuplicates(Node *root)
    {
        if (!head)
            return head;
        set<int> s;
        Node *slow = head, *fast = head->next;
        s.insert(slow->data);
        while (fast)
        {
            if (s.find(fast->data) != s.end())
                slow->next = fast->next;
            else
            {
                s.insert(fast->data);
                slow = fast;
            }
            fast = fast->next;
        }
        return head;
    }
};

int main()
{

    LinkedList ll1;
    ll1.push(4);
    ll1.push(2);
    ll1.push(2);
    ll1.push(5);

    ll1.head = ll1.removeDuplicates(ll1.head);
    ll1.print();
    cout << "\n";

    LinkedList ll2;
    ll2.push(2);
    ll2.push(2);
    ll2.push(2);
    ll2.push(2);
    ll2.push(2);

    ll2.head = ll2.removeDuplicates(ll2.head);
    ll2.print();
    cout << "\n";

    return 0;
}