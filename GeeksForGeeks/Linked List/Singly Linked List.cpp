#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
// + Dynamic Size
// + Ease Insertion and Deletion

// - No Random Access
// - Extra Memory of pointers
// - Not cache friendly, due to non contiguous locations

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int main()
{
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;

    first = new Node();
    second = new Node();
    third = new Node();

    first->data = 1;
    second->data = 2;
    third->data = 3;
    first->next = second;
    second->next = third;
    third->next = NULL;

    display(first);
}