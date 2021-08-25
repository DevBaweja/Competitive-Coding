#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    bool isEnd;
    map<char, TrieNode *> children;
    TrieNode()
    {
        isEnd = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *temp = root;
        int i = 0;
        while (i < word.size())
        {
            char el = word[i];
            if (temp->children.find(el) == temp->children.end())
                temp->children[el] = new TrieNode();
            temp = temp->children[el];
            i++;
        }
        temp->isEnd = true;
    }

    bool search(string word)
    {
        TrieNode *temp = root;
        int i = 0;
        while (i < word.size())
        {
            char el = word[i];
            if (temp->children.find(el) == temp->children.end())
                return false;
            temp = temp->children[el];
            i++;
        }
        return temp->isEnd;
    }

    bool startsWith(string prefix)
    {
        TrieNode *temp = root;
        int i = 0;
        while (i < prefix.size())
        {
            char el = prefix[i];
            if (temp->children.find(el) == temp->children.end())
                return false;
            temp = temp->children[el];
            i++;
        }
        return true;
    }
};