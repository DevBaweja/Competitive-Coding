#include <bits/stdc++.h>
using namespace std;

// Prefix Setting and Checking
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string prefix = "";
    string cand = strs[n - 1];
    for (int index = 0; index < cand.size(); index++)
    {
        for (int k = 0; k < n; k++)
        {
            if (index >= strs[k].size() || (k > 0 && strs[k - 1][index] != strs[k][index]))
                return prefix;
        }
        prefix += cand[index];
    }
    return prefix;
}

// Trie and Count Path
class TrieNode
{
public:
    int count;
    unordered_map<char, TrieNode *> children;
    TrieNode()
    {
        count = 0;
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
    void insert(string str, string res, string &ans, int n)
    {
        int k = str.size();
        TrieNode *temp = root;
        for (int i = 0; i < k; i++)
        {
            char el = str[i];
            res += el;
            if (temp->children.find(el) == temp->children.end())
                temp->children[el] = new TrieNode();
            temp = temp->children[el];
            temp->count++;
            if (temp->count == n && res.size() > ans.size())
                ans = res;
        }
    }
};
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    Trie *t = new Trie();
    string res = "", ans = "";
    for (string str : strs)
        t->insert(str, res, ans, n);
    return ans;
}