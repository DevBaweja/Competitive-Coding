#include <bits/stdc++.h>
using namespace std;

// DFS with Backtracking
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

bool dfs(vector<vector<char>> &board, string word, int i, int j, int n, int m, int index, vector<vector<bool>> &visited)
{
    if (visited[i][j])
        return false;
    if (index == word.size() - 1 && word[index] == board[i][j])
        return true;
    if (word[index] != board[i][j])
        return false;

    visited[i][j] = true;
    vector<int> dirX{1, 0, 0, -1};
    vector<int> dirY{0, 1, -1, 0};
    int dir = 4;
    for (int k = 0; k < dir; k++)
    {
        int nx = i + dirX[k];
        int ny = j + dirY[k];
        if (isSafe(nx, ny, n, m) && dfs(board, word, nx, ny, n, m, index + 1, visited))
        {
            visited[i][j] = false;
            return true;
        }
    }

    return visited[i][j] = false;
}

bool findWordsUtil(vector<vector<char>> &board, string word, int n, int m)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (dfs(board, word, i, j, n, m, 0, visited))
                return true;
    return false;
}

vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
{
    int n = board.size();
    int m = board[n - 1].size();
    vector<string> ans;
    for (string word : words)
        if (findWordsUtil(board, word, n, m))
            ans.push_back(word);
    return ans;
}

// DFS with Backtracking and Trie
class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    string word;
    TrieNode()
    {
        word = "";
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
        int n = word.size();
        TrieNode *temp = root;
        for (int el : word)
        {
            if (temp->children.find(el) == temp->children.end())
                temp->children[el] = new TrieNode();
            temp = temp->children[el];
        }
        temp->word = word;
    }
};

class Solution
{
public:
    bool isSafe(int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    void dfs(vector<vector<char>> &board, TrieNode *t, int i, int j, int n, int m, vector<vector<bool>> &visited, vector<string> &ans, vector<int> &dirX, vector<int> &dirY)
    {
        char cand = board[i][j];
        if (t->children.find(cand) == t->children.end())
            return;
        t = t->children[cand];
        if (t->word != "")
        {
            ans.push_back(t->word);
            t->word = "";
        }
        visited[i][j] = true;
        int dir = 4;
        for (int k = 0; k < dir; k++)
        {
            int nx = i + dirX[k];
            int ny = j + dirY[k];
            if (isSafe(nx, ny, n, m) && !visited[nx][ny])
                dfs(board, t, nx, ny, n, m, visited, ans, dirX, dirY);
        }
        visited[i][j] = false;
    }

    void findWordsUtil(vector<vector<char>> &board, Trie *t, int n, int m, vector<string> &ans)
    {
        vector<int> dirX{1, 0, 0, -1};
        vector<int> dirY{0, 1, -1, 0};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        TrieNode *k = t->root;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dfs(board, k, i, j, n, m, visited, ans, dirX, dirY);
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int n = board.size();
        int m = board[n - 1].size();
        vector<string> ans;
        Trie *t = new Trie();

        for (string word : words)
            t->insert(word);
        findWordsUtil(board, t, n, m, ans);
        return ans;
    }
};

// DFS with backtracking and Trie Optimized
class TrieNode
{
public:
    vector<TrieNode *> children;
    string word;
    TrieNode()
    {
        int size = 26;
        children = vector<TrieNode *>(size, NULL);
        word = "";
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
        int n = word.size();
        TrieNode *temp = root;
        for (char el : word)
        {
            int ch = el - 'a';
            if (!temp->children[ch])
                temp->children[ch] = new TrieNode();
            temp = temp->children[ch];
        }
        temp->word = word;
    }
};

class Solution
{
public:
    bool isSafe(int x, int y, int n, int m)
    {
        return (x >= 0 && y >= 0 && x < n && y < m);
    }

    void dfs(vector<vector<char>> &board, TrieNode *t, int i, int j, int n, int m, vector<vector<bool>> &visited, vector<string> &ans, vector<int> &dirX, vector<int> &dirY)
    {
        char cand = board[i][j];
        int ch = cand - 'a';
        if (!t->children[ch])
            return;
        t = t->children[ch];
        if (t->word != "")
        {
            ans.push_back(t->word);
            t->word = "";
        }

        visited[i][j] = true;
        int dir = 4;
        for (int k = 0; k < dir; k++)
        {
            int nx = i + dirX[k];
            int ny = j + dirY[k];
            if (isSafe(nx, ny, n, m) && !visited[nx][ny])
                dfs(board, t, nx, ny, n, m, visited, ans, dirX, dirY);
        }
        visited[i][j] = false;
    }

    void findWordsUtil(vector<vector<char>> &board, vector<string> words, Trie *t, int n, int m, vector<string> &ans)
    {
        vector<int> dirX{1, 0, 0, -1};
        vector<int> dirY{0, 1, -1, 0};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        TrieNode *k = t->root;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                dfs(board, k, i, j, n, m, visited, ans, dirX, dirY);
                if (ans.size() == words.size())
                    return;
            }
    }

    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        int n = board.size();
        int m = board[n - 1].size();
        vector<string> ans;
        Trie *t = new Trie();

        for (string word : words)
            t->insert(word);
        findWordsUtil(board, words, t, n, m, ans);
        return ans;
    }
};