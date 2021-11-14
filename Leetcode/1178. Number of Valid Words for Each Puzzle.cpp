#include <bits/stdc++.h>
using namespace std;

// Hashing
vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
{
    unordered_map<char, unordered_set<string>> puzzlesHash;
    unordered_map<string, unordered_set<char>> wordsSet;
    for (string word : words)
    {
        unordered_set<char> unique;
        for (char letter : word)
            unique.insert(letter);
        wordsSet[word] = unique;
    }

    for (string puzzle : puzzles)
    {
        char letter = puzzle[0];
        for (string word : words)
        {
            unordered_set<char> unique = wordsSet[word];
            if (unique.find(letter) != unique.end())
                puzzlesHash[letter].insert(word);
        }
    }

    vector<int> ans;
    for (string puzzle : puzzles)
    {
        char letter = puzzle[0];
        unordered_set<string> cands = puzzlesHash[letter];

        unordered_set<char> puzzleSet;
        for (char letter : puzzle)
            puzzleSet.insert(letter);

        int count = 0;
        for (string cand : cands)
        {
            unordered_set<char> unique = wordsSet[cand];
            bool res = true;
            for (char letter : unique)
            {
                if (puzzleSet.find(letter) == puzzleSet.end())
                {
                    res &= false;
                    if (!res)
                        break;
                }
            }
            count += res;
        }
        ans.push_back(count);
    }
    return ans;
}

// Bit Masking
int generateMask(string s)
{
    int mask = 0;
    for (char ch : s)
        mask |= (1 << (ch - 'a'));
    return mask;
}

vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
{
    unordered_map<char, vector<int>> puzzlesHash;
    unordered_map<string, int> wordsSet;
    for (string word : words)
        wordsSet[word] = generateMask(word);

    for (string puzzle : puzzles)
    {
        int letter = puzzle[0];
        if (puzzlesHash.find(letter) != puzzlesHash.end())
            continue;
        for (string word : words)
        {
            int mask = wordsSet[word];
            if (mask & (1 << (letter - 'a')))
                puzzlesHash[letter].push_back(mask);
        }
    }

    vector<int> ans;
    for (string puzzle : puzzles)
    {
        char letter = puzzle[0];
        vector<int> candsMask = puzzlesHash[letter];

        int puzzleMask = generateMask(puzzle);

        int count = 0;
        for (int candMask : candsMask)
            if ((candMask & puzzleMask) == candMask)
                count++;
        ans.push_back(count);
    }
    return ans;
}

// Trie
class Node
{
public:
    unordered_map<char, Node *> m;
    int c;
    Node()
    {
        c = 0;
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

    void insert(string v)
    {
        Node *t = root;
        for (char ch : v)
        {
            if (t->m.find(ch) == t->m.end())
                t->m[ch] = new Node();
            t = t->m[ch];
        }
        t->c++;
    }
};

int count(Node *root, string str, bool seen, char letter)
{
    if (!root)
        return 0;

    int cnt = 0;
    if (seen)
        cnt += root->c;

    for (char ch : str)
    {
        if (root->m.find(ch) == root->m.end())
            continue;
        cnt += count(root->m[ch], str, seen || letter == ch, letter);
    }
    return cnt;
}

vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
{
    Trie *t = new Trie();

    for (string word : words)
    {
        set<char> s;
        for (char ch : word)
            s.insert(ch);

        string str = "";
        for (char ch : s)
            str += ch;
        t->insert(str);
    }
    vector<int> res;
    for (string puzzle : puzzles)
    {
        char letter = puzzle[0];
        sort(puzzle.begin(), puzzle.end());
        res.push_back(count(t->root, puzzle, false, letter));
    }
    return res;
}