#include <bits/stdc++.h>
using namespace std;
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TrieNode
{
    TrieNode *children[ALPHABET_SIZE];
    bool isLeaf;
};

TrieNode *getNode(void)
{
    TrieNode *pNode = new TrieNode();

    pNode->isLeaf = false;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

void insert(TrieNode *root, string key)
{
    int i = 0;
    TrieNode *t = root;
    while (i < key.size())
    {
        int v = CHAR_TO_INDEX(key[i]);
        if (t->children[v] == NULL)
            t->children[v] = getNode();
        t = t->children[v];
        i++;
    }
    t->isLeaf = true;
}

bool search(TrieNode *root, string key)
{
    int i = 0;
    TrieNode *t = root;
    while (i < key.size())
    {
        int v = CHAR_TO_INDEX(key[i]);
        if (t->children[v] == NULL)
            return false;
        t = t->children[v];
        i++;
    }
    return t->isLeaf;
}