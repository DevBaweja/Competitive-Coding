#include <bits/stdc++.h>
using namespace std;

// Two Trie for prefix and suffix search
// Intersection of prefix and suffix indexex
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    vector<int> path;
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word, int index)
    {
        TrieNode *t = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            char v = word[i];
            if (t->children.find(v) == t->children.end())
                t->children[v] = new TrieNode();
            t = t->children[v];
            t->path.push_back(index);
        }
    }
    vector<int> search(string word)
    {
        TrieNode *t = root;
        int n = word.size();
        for (int i = 0; i < n; i++)
        {
            char v = word[i];
            if (t->children.find(v) == t->children.end())
                return {};
            t = t->children[v];
        }
        return t->path;
    }
};
class WordFilter
{
public:
    vector<string> words;
    int n;
    Trie *pre, *suf;
    WordFilter(vector<string> &words)
    {
        this->words = words;
        n = words.size();
        pre = new Trie();
        suf = new Trie();
        for (int index = 0; index < n; index++)
        {
            string word = words[index];
            pre->insert(word, index);
            reverse(word.begin(), word.end());
            suf->insert(word, index);
        }
    }

    int f(string prefix, string suffix)
    {
        vector<int> preV = pre->search(prefix);
        reverse(suffix.begin(), suffix.end());
        vector<int> sufV = suf->search(suffix);
        int n = preV.size(), m = sufV.size();
        vector<int> v;
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0)
        {
            int left = preV[i], right = sufV[j];
            if (left < right)
                j--;
            else if (left > right)
                i--;
            else
                return (left + right) / 2;
        }
        return -1;
    }
};