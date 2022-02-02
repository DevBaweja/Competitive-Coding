#include <bits/stdc++.h>
using namespace std;

// Brute Force
bool isVowel(char el)
{
    vector<char> v{'a', 'e', 'i', 'o', 'u'};
    for (int ch : v)
        if (ch == el)
            return true;
    return false;
}

char complement(char s)
{
    if (s >= 'a' && s <= 'z')
        return s - 32;
    if (s >= 'A' && s <= 'Z')
        return s + 32;
    return 'a';
}

string spellcheckerUtil(vector<string> &wordlist, int n, string &query)
{
    int m = query.size();

    auto it = find(wordlist.begin(), wordlist.end(), query);
    if (it != wordlist.end())
        return *it;

    vector<string> ans;
    ans.push_back("");

    for (int i = 0; i < m; i++)
    {
        int size = ans.size();
        char el = query[i];
        for (int i = 0; i < size; i++)
        {
            string already = ans[i];
            ans.push_back(already + el);
            ans.push_back(already + complement(el));
            if (isVowel(el))
            {
                vector<char> v{'a', 'e', 'i', 'o', 'u'};
                for (char ch : v)
                    if (ch != el)
                        ans.push_back(already + ch);
            }
        }
    }

    for (string word : wordlist)
        if (find(ans.begin(), ans.end(), word) != ans.end())
            return word;

    return "";
}

vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
{
    int n = wordlist.size();
    int m = queries.size();
    vector<string> res;
    for (string query : queries)
        res.push_back(spellcheckerUtil(wordlist, n, query));
    return res;
}

// Trie
class Node
{
public:
    unordered_map<char, Node *> children;
    bool isEnd;
    Node()
    {
        isEnd = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string str)
    {
        Node *crawl = root;
        for (char ch : str)
        {
            if (crawl->children.find(ch) == crawl->children.end())
                crawl->children[ch] = new Node();
            crawl = crawl->children[ch];
        }
        crawl->isEnd = true;
    }
};

bool isVowel(char el)
{
    vector<char> v{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int ch : v)
        if (ch == el)
            return true;
    return false;
}

char complement(char s)
{
    if (s >= 'a' && s <= 'z')
        return s - 32;
    if (s >= 'A' && s <= 'Z')
        return s + 32;
    return 'a';
}

void lookup(Node *root, string query, string res, int priority, unordered_map<int, vector<string>> &ans)
{
    if (!root)
        return;
    if (res.size() == query.size() && root->isEnd)
    {
        ans[priority].push_back(res);
        return;
    }

    vector<pair<char, int>> possible;
    char ch = query[res.size()];
    possible.push_back({ch, max(priority, 0)});
    possible.push_back({complement(ch), max(priority, 1)});

    if (isVowel(ch))
    {
        vector<char> v{'a', 'e', 'i', 'o', 'u'};
        for (char &el : v)
        {
            if (el != ch)
            {
                possible.push_back({el, max(priority, 2)});
                possible.push_back({complement(el), max(priority, 2)});
            }
        }
    }

    for (pair<char, int> &p : possible)
    {
        char pos = p.first;
        int pri = p.second;
        if (root->children.find(pos) != root->children.end())
            lookup(root->children[pos], query, res + pos, pri, ans);
    }
}

class Solution
{
public:
    vector<string> spellchecker(vector<string> &wordlist, vector<string> &queries)
    {
        int n = wordlist.size();
        int m = queries.size();
        Trie *t = new Trie();
        for (string word : wordlist)
            t->insert(word);

        vector<string> res;
        int priority = 3;
        for (string &query : queries)
        {
            unordered_map<int, vector<string>> ans;
            lookup(t->root, query, "", INT_MIN, ans);
            bool flag = false;
            for (int pri = 0; pri < priority; pri++)
            {
                for (string &word : wordlist)
                {
                    if (find(ans[pri].begin(), ans[pri].end(), word) != ans[pri].end())
                    {
                        res.push_back(word);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (!flag)
                res.push_back("");
        }

        return res;
    }
};

// TODO
// Hashing
// Regex
// Trie