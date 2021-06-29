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
    void deleteNode(Node* del){
        Node* node = del;
        Node* prev;
        
        while(node->next){
            node->data = node->next->data;
            prev = node;
            node = node->next;
        }
        prev->next = NULL;
    }
*/

void deleteNode(Node *del)
{
    Node *node = del;
    Node *next = node->next;
    node->data = next->data;
    node->next = next->next;
}

/*
    void deleteNode(Node *del)
    {
       *del = *(del->next);
    }
*/
