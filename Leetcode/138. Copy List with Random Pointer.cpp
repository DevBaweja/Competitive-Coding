#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node *copyRandomList(Node *head)
{
    if (!head)
        return head;
    unordered_map<Node *, Node *> m;

    Node *dummy = new Node(-1);
    Node *copy;
    copy = dummy;
    Node *temp;
    temp = head;
    while (temp)
    {
        copy->next = new Node(temp->val);
        copy = copy->next;
        m[temp] = copy;
        temp = temp->next;
    }

    copy = dummy;
    temp = head;
    while (temp)
    {
        copy->next->random = m[temp->random];
        copy = copy->next;
        temp = temp->next;
    }
    return dummy->next;
}

// Using space
// Time - O(2n)
// Space - O(n)
Node* copyRandomList(Node* head) {
    if(!head) return head;
    unordered_map<Node*, Node*> mp;
    Node* ans = new Node(-1);
    Node* res = ans;
    Node* cur = head;
    while(cur) {
        res->next = new Node(cur->val);
        res = res->next;
        mp[cur] = res;
        cur = cur->next;
    }
    Node* ncur = head;
    while(ncur) {
        if(mp.find(ncur->random) != mp.end()) {
            mp[ncur]->random = mp[ncur->random];
        }
        ncur = ncur->next;
    }
    return ans->next;
}

// Time - O(n)
// Space - O(n)
// Avoid map
Node* copyRandomList(Node* head) {
    if(!head) return head;
    Node* cur = head;
    // Interweave
    while(cur) {
        Node *next = cur->next;
        Node *node = new Node(cur->val);
        cur->next = node;
        node->next = next;
        cur = next;
    }
    // Assign random
    cur = head;
    while(cur) {
        Node *rand = cur->random;
        Node *copy = cur->next;
        if(rand)
            copy->random = rand->next;
        cur = copy->next;
    }

    cur = head;

    // Restore
    Node *ans = new Node(-1);
    Node *res = ans;
    while(cur && cur->next) {
        Node *copy = cur->next;
        cur->next = copy->next;

        res->next = copy;            
        res = res->next;

        cur = copy->next;
    }
    return ans->next;
}