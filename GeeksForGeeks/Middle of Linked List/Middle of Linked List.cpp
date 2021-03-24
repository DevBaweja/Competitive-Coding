#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};
// Slow and Fast Pointer

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void print(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int middleElementPointer(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
    {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr->data;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);

    print(head);
    cout << endl;
    cout << middleElementPointer(head);
    return 0;
}
