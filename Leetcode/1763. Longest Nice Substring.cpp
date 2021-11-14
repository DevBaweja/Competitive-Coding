#include <bits/stdc++.h>
using namespace std;

// Brute Force
char complement(char s)
{
    if (s >= 'a' && s <= 'z')
        return s - 32;
    if (s >= 'A' && s <= 'Z')
        return s + 32;
    return 'dev';
}

bool isValid(unordered_map<char, int> &m)
{
    for (pair<char, int> el : m)
        if (m.find(complement(el.first)) == m.end())
            return false;
    return true;
}

string longestNiceSubstring(string s)
{
    int n = s.size();
    int size = INT_MIN;
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        string str = "";
        unordered_map<char, int> m;
        for (int j = i; j < n; j++)
        {
            str += s[j];
            m[s[j]]++;
            if (isValid(m) && size < j - i)
            {
                size = j - i;
                start = i;
            }
        }
    }
    if (size == INT_MIN)
        return "";
    return s.substr(start, size + 1);
}

// Sliding Window
// Doesn't work
char complement(char s)
{
    if (s >= 'a' && s <= 'z')
        return s - 32;
    if (s >= 'A' && s <= 'Z')
        return s + 32;
    return 'dev';
}

string longestNiceSubstring(string s)
{
    int n = s.size();
    int size = INT_MAX;
    int start = -1;

    int bad = 0;
    int low = 0;

    unordered_map<char, int> bm;
    unordered_map<char, int> m;
    for (int high = 0; high < n; high++)
    {
        char acquire = s[high];
        m[acquire]++;
        if (m.find(complement(acquire)) == m.end())
        {
            if (bm.find(acquire) == bm.end())
                bad++;
            bm[acquire]++;
        }
        else
        {
            if (bm.find(complement(acquire)) != bm.end())
            {
                bad -= bm[complement(acquire)];
                bm.erase(complement(acquire));
            }
        }

        if (!bad)
        {
            if (size > high - low)
            {
                size = high - low;
                start = low;
            }
            char release = s[low];
        }
    }

    if (size == INT_MIN)
        return "";
    return s.substr(start, size + 1);
}

// TODO
// Divide and Conquer
