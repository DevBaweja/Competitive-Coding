#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
/*
    void addNode(Node* &temp, int data){
        temp->next = new Node(data);
        temp = temp->next;
    }
    
    struct compare{
        bool operator()(Node* a, Node* b){
            return a->data > b->data;
        }
    };
    // Time - O(n*log(k)) Space - O(k)
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node *arr[], int K)
    {
        priority_queue<Node*, vector<Node*>,compare> pq;
        
        for(int i=0;i<K;i++){
            if(arr[i])
                pq.push(arr[i]);
        }
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while(!pq.empty()){
            Node* el = pq.top();
            pq.pop();
            
            addNode(temp, el->data);
            if(el->next)
                pq.push(el->next);
        }
        return dummy->next;
    }
*/

Node *mergeSorted(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    Node *res = NULL;
    if (a->data <= b->data)
    {
        res = a;
        res->next = mergeSorted(a->next, b);
    }
    else
    {
        res = b;
        res->next = mergeSorted(a, b->next);
    }
    return res;
}
// Time - O(n*log(k)) Space - O(1)
//Function to merge K sorted linked list.
Node *mergeKLists(Node *arr[], int K)
{
    K--;
    while (K != 0)
    {
        int i = 0, j = K;
        while (i < j)
        {
            arr[i] = mergeSorted(arr[i++], arr[j--]);
            if (i >= j)
                K = j;
        }
    }
    return arr[0];
}
