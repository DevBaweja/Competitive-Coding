#include <bits/stdc++.h>
using namespace std;

struct Node
{
    map<char, Node *> children;
    bool isEnd;
    Node()
    {
        isEnd = false;
    }
};

struct Trie
{
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string s)
    {
        Node *t = root;
        int i = 0;
        while (i < s.size())
        {
            int v = s[i];
            if (t->children.find(v) == t->children.end())
                t->children[v] = new Node();
            t = t->children[v];
            i++;
        }
        t->isEnd = true;
    }

    bool search(string s)
    {
        Node *t = root;
        int i = 0;
        while (i < s.size())
        {
            int v = s[i];
            if (t->children.find(v) == t->children.end())
                return false;
            t = t->children[v];

            i++;
        }
        return t->isEnd;
    }

    void dfs(Node *cur, string prefix, vector<string> &res)
    {
        if (cur->isEnd)
            res.push_back(prefix);

        for (pair<char, Node *> el : cur->children)
        {
            Node *next = el.second;
            dfs(next, prefix + el.first, res);
        }
    }

    vector<vector<string>> prefix(string s)
    {
        int n = s.size();
        vector<vector<string>> res(n);
        Node *cur = root;
        string prefix = "";
        int i = 0;
        while (i < n)
        {
            char v = s[i];
            prefix += v;
            if (cur->children.find(v) == cur->children.end())
                break;
            Node *next = cur->children[v];
            dfs(next, prefix, res[i]);
            cur = next;
            i++;
        }
        while (i < n)
            res[i++] = {"0"};
        return res;
    }
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    Trie *t = new Trie();
    for (int i = 0; i < n; i++)
        t->insert(contact[i]);
    vector<vector<string>> res = t->prefix(s);
    return res;
}
