#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int val;
    Node *left, *right;
    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        left = right = NULL;
    }
};

class LinkedList
{
public:
    Node *front, *back;
    LinkedList()
    {
        front = new Node(-1, -1);
        back = new Node(-1, -1);
        front->right = back;
        back->left = front;
    }
    Node *addNodeAtFront(Node *node)
    {
        Node *next = front->right;
        front->right = node;
        node->left = front;
        node->right = next;
        next->left = node;
        return node;
    }
    Node *removeNodeAtBack()
    {
        Node *node = back->left;
        Node *prev = node->left;
        return removeNode(node);
    }

    Node *removeNode(Node *node)
    {
        Node *prev = node->left;
        Node *next = node->right;
        prev->right = node->right;
        next->left = node->left;
        node->left = node->right = NULL;
        return node;
    }
};

class LRUCache
{
public:
    int cap;
    unordered_map<int, Node *> m;
    LinkedList *ll;
    LRUCache(int cap)
    {
        this->cap = cap;
        ll = new LinkedList();
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        m[key] = ll->addNodeAtFront(ll->removeNode(m[key]));
        return m[key]->val;
    }

    void put(int key, int val)
    {
        if (m.find(key) == m.end())
        {
            if (m.size() < cap)
                m[key] = ll->addNodeAtFront(new Node(key, val));
            else
            {
                Node *node = ll->removeNodeAtBack();
                m.erase(node->key);
                m[key] = ll->addNodeAtFront(new Node(key, val));
            }
        }
        else
        {
            Node *node = ll->removeNode(m[key]);
            node->val = val;
            m[key] = ll->addNodeAtFront(node);
        }
    }
};
