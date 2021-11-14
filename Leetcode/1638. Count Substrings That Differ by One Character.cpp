#include <bits/stdc++.h>
using namespace std;

// Two Loops and Two Pointers
// Time- O(n3)
int countSubstrings(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int diff = 0;
            int x = i, y = j;
            while (x < n && y < m && diff != 2)
            {
                if (s[x++] != t[y++])
                    diff++;
                if (diff == 1)
                    count++;
            }
        }
    }
    return count;
}

// Two Loops and Middle
// Time- O(n3)
int countSubstrings(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] != t[j])
            {
                int l = 1, r = 1;
                while (min(i - l, j - l) >= 0 && s[i - l] == t[j - l])
                    l++;
                while (i + r < n && j + r < m && s[i + r] == t[j + r])
                    r++;
                count += l * r;
            }
        }
    }
    return count;
}

// 2 DP of Left and Right
// Time - O(n2)
int countSubstrings(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int count = 0;
    vector<vector<int>> dpl(n, vector<int>(m, 0));
    vector<vector<int>> dpr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i] == t[j])
            {
                int prev = 0;
                if (i && j)
                    prev = dpl[i - 1][j - 1];
                dpl[i][j] = 1 + prev;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (s[i] == t[j])
            {
                int next = 0;
                if (i != n - 1 && j != m - 1)
                    next = dpr[i + 1][j + 1];
                dpr[i][j] = 1 + next;
            }
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i] != t[j])
            {
                int prev = 0;
                if (i && j)
                    prev = dpl[i - 1][j - 1];
                int next = 0;
                if (i != n - 1 && j != m - 1)
                    next = dpr[i + 1][j + 1];
                count += (prev + 1) * (next + 1);
            }
    return count;
}

// 2 DP of Same and Different
// Time - O(n2)
int countSubstrings(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> same(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> differ(n + 1, vector<int>(m + 1, 0));
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                same[i][j] = 1 + same[i - 1][j - 1];
                differ[i][j] = differ[i - 1][j - 1];
            }
            else
                differ[i][j] = 1 + same[i - 1][j - 1];
            count += differ[i][j];
        }
    }
    return count;
}

// TODO
// Trie