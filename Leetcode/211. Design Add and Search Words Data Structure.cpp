#include <bits/stdc++.h>
using namespace std;

// Trie and Depth First Search and Backtracking
class TrieNode
{
public:
    bool isEnd;
    unordered_map<char, TrieNode *> children;
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
        TrieNode *t = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            int v = word[i];
            if (t->children.find(v) == t->children.end())
                t->children[v] = new TrieNode();
            t = t->children[v];
        }
        t->isEnd = true;
    }
    bool search(TrieNode *root, string word, int index)
    {
        int n = word.size();
        if (index == n)
            return root->isEnd;

        char el = word[index];
        if (el != '.')
        {
            if (root->children.find(el) == root->children.end())
                return false;
            return search(root->children[el], word, index + 1);
        }

        bool res = false;
        for (pair<char, TrieNode *> next : root->children)
            res |= search(next.second, word, index + 1);
        return res;
    }
};

class WordDictionary
{
public:
    Trie *t;
    WordDictionary()
    {
        t = new Trie();
    }

    void addWord(string word)
    {
        t->insert(word);
    }

    bool search(string word)
    {
        return t->search(t->root, word, 0);
    }
};
