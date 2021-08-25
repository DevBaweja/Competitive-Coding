#include <bits/stdc++.h>
using namespace std;

struct Node
{
    unordered_map<char, Node *> children;
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
};

int main()
{
    Trie *t = new Trie();
    vector<string> keys = {"the", "a", "there",
                           "answer", "any", "by",
                           "bye", "their"};
    for (string key : keys)
        t->insert(key);
    vector<string> finds = {"the", "these", "their", "thaw"};
    for (string find : finds)
        cout << t->search(find) << endl;
}