#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    int val;
    int freq;
    Node *left, *right;
    Node(int key, int val, int freq)
    {
        this->key = key;
        this->val = val;
        this->freq = freq;
        left = right = NULL;
    }
};

class LinkedList
{
public:
    Node *front, *back;
    int size;
    LinkedList()
    {
        front = new Node(-1, -1, -1);
        back = new Node(-1, -1, -1);
        front->right = back;
        back->left = front;
        size = 0;
    }
    Node *addNodeAtFront(Node *node)
    {
        size++;
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
        size--;
        Node *prev = node->left;
        Node *next = node->right;
        prev->right = node->right;
        next->left = node->left;
        node->left = node->right = NULL;
        return node;
    }
};

class LFUCache
{
public:
    int cap;
    unordered_map<int, Node *> m;
    unordered_map<int, LinkedList *> n;
    int freq;
    LFUCache(int cap)
    {
        this->cap = cap;
        this->freq = 0;
    }

    int get(int key)
    {
        if (!cap)
            return -1;
        if (m.find(key) == m.end())
            return -1;
        Node *node = n[m[key]->freq]->removeNode(m[key]);

        if (n[node->freq]->size == 0)
        {
            n.erase(node->freq);
            if (node->freq == freq)
                freq = node->freq + 1;
        }

        int cur = ++node->freq;

        if (n.find(cur) == n.end())
            n[cur] = new LinkedList();

        m[key] = n[cur]->addNodeAtFront(node);
        return m[key]->val;
    }

    void put(int key, int val)
    {
        if (!cap)
            return;
        if (m.find(key) == m.end())
        {
            if (m.size() < cap)
            {
                freq = 1;
                if (n.find(freq) == n.end())
                    n[freq] = new LinkedList();
                m[key] = n[freq]->addNodeAtFront(new Node(key, val, freq));
            }
            else
            {
                Node *node = n[freq]->removeNodeAtBack();
                m.erase(node->key);
                freq = 1;
                if (n.find(freq) == n.end())
                    n[freq] = new LinkedList();

                m[key] = n[freq]->addNodeAtFront(new Node(key, val, freq));
            }
        }
        else
        {
            Node *node = n[m[key]->freq]->removeNode(m[key]);
            node->val = val;
            if (n[node->freq]->size == 0)
            {
                n.erase(node->freq);
                if (node->freq == freq)
                    freq = node->freq + 1;
            }
            int cur = ++node->freq;

            if (n.find(cur) == n.end())
                n[cur] = new LinkedList();

            m[key] = n[cur]->addNodeAtFront(node);
        }
    }
};