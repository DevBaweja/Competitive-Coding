#include <bits/stdc++.h>
using namespace std;

// BFS
string pushDominoes(string v)
{
    int n = v.size();

    queue<pair<char, int>> q;

    for (int i = 0; i < n; i++)
    {
        char el = v[i];
        if (el != '.')
            q.push({el, i});
    }
    while (!q.empty())
    {
        int size = q.size();
        vector<bool> vis(n, false);
        while (size--)
        {
            pair<char, int> p = q.front();
            q.pop();
            char el = p.first;
            int index = p.second;
            if (v[index] == '.')
                continue;
            if (el == 'R' && index != n - 1)
            {
                if (!vis[index + 1] && v[index + 1] == '.')
                {
                    q.push({el, index + 1});
                    vis[index + 1] = true;
                    v[index + 1] = 'R';
                }
                else if (vis[index + 1] && v[index + 1] == 'L')
                    v[index + 1] = '.';
            }
            if (el == 'L' && index != 0)
            {
                if (!vis[index - 1] && v[index - 1] == '.')
                {
                    q.push({el, index - 1});
                    vis[index - 1] = true;
                    v[index - 1] = 'L';
                }
                else if (vis[index - 1] && v[index - 1] == 'R')
                    v[index - 1] = '.';
            }
        }
    }
    return v;
}

// String Manipulation
void replaceAll(string &str, string from, string to)
{
    if (!from.length())
        return;

    int startPos = 0;
    while ((startPos = str.find(from, startPos)) != string::npos)
    {
        str = str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
}

string pushDominoes(string v)
{
    string s1 = v;
    while (true)
    {
        string s2 = s1;
        if (s2.find("R.L") != string::npos)
            replaceAll(s2, "R.L", "S");
        if (s2.find("R.") != string::npos)
            replaceAll(s2, "R.", "RR");
        if (s2.find(".L") != string::npos)
            replaceAll(s2, ".L", "LL");
        if (s1 == s2)
            break;
        s1 = s2;
    }
    replaceAll(s1, "S", "R.L");
    return s1;
}