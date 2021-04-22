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

    Node *reverse(Node *head)
    {
        Node *curr = head, *prev = NULL, *next = NULL;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isIdentical(Node *head1, Node *head2)
    {
        Node *temp1 = head1, *temp2 = head2;
        while (temp1 && temp2)
        {
            if (temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 || temp2)
            return false;
        return true;
    }

    bool isPalindromeReverse(Node *head)
    {
        bool res = true;
        Node *slow = head, *fast = head, *prev_slow = NULL;
        Node *mid = NULL;
        Node *first_half = head, *second_half = NULL;

        if (head && head->next)
        {
            while (fast && fast->next)
            {
                fast = fast->next->next;
                prev_slow = slow;
                slow = slow->next;
            }

            // Odd List
            if (fast)
            {
                mid = slow;
                slow = slow->next;
            }

            second_half = slow;
            prev_slow->next = NULL;
            second_half = reverse(second_half);

            res = isIdentical(first_half, second_half);

            second_half = reverse(second_half);

            if (mid)
            {
                prev_slow->next = mid;
                mid->next = second_half;
            }
            else
                prev_slow->next = second_half;
        }
        return res;
    }

    bool isPalindromeRecursive(Node *head)
    {
    }

    bool isPalindrome(Node *head)
    {
        stack<int> s;
        Node *temp;
        temp = head;
        while (temp)
        {
            s.push(temp->data);
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            if (s.top() != temp->data)
                return false;
            s.pop();
            temp = temp->next;
        }
        return true;
    }
};

int main()
{

    LinkedList ll;
    ll.push(1);
    ll.push(2);
    // ll.push(3);
    ll.push(2);
    ll.push(1);

    cout << ll.isPalindrome(ll.head) << endl;
    cout << ll.isPalindromeReverse(ll.head) << endl;

    return 0;
}