#include <bits/stdc++.h>
using namespace std;

// Brute Force
// Time - O(n2)
vector<int> shortestToChar(string s, char c)
{
    int n = s.size();
    vector<int> res(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            res[i] = 0;
            continue;
        }
        for (int j = i - 1; j >= 0; j--)
        {
            if (s[j] == c)
            {
                res[i] = min(res[i], i - j);
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] == c)
            {
                res[i] = min(res[i], j - i);
                break;
            }
        }
    }
    return res;
}

// Binary Search
// O(nlog(n))
vector<int> shortestToChar(string s, char c)
{
    int n = s.size();
    vector<int> res(n, INT_MAX);
    vector<int> v;
    for (int i = 0; i < n; i++)
        if (s[i] == c)
            v.push_back(i);

    int k = v.size();
    for (int index = 0; index < n; index++)
    {
        int low = 0, high = k - 1;
        bool flag = false;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (v[mid] == index)
            {
                res[index] = 0;
                flag = true;
                break;
            }
            if (v[mid] > index)
                high = mid - 1;
            else
                low = mid + 1;
        }
        if (!flag)
        {
            int mini = INT_MAX;
            if (low != k)
                mini = min(mini, v[low] - index);
            if (high != -1)
                mini = min(mini, index - v[high]);
            res[index] = mini;
        }
    }
    return res;
}

// Prefix and Suffix Sum
// Time - O(n)
// Space - O(n)
vector<int> shortestToChar(string s, char c)
{
    int n = s.size();
    vector<int> res(n, INT_MAX);

    int pos = -n;
    vector<int> prefix(n, INT_MAX);
    if (s[0] == c)
        prefix[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == c)
        {
            prefix[i] = 0;
            res[i] = 0;
        }
        else
        {
            if (prefix[i - 1] != INT_MAX)
            {
                prefix[i] = prefix[i - 1] + 1;
                res[i] = min(res[i], prefix[i]);
            }
        }
    }
    vector<int> suffix(n, INT_MAX);
    if (s[n - 1] == c)
        suffix[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == c)
        {
            suffix[i] = 0;
            res[i] = 0;
        }
        else
        {
            if (suffix[i + 1] != INT_MAX)
            {
                suffix[i] = suffix[i + 1] + 1;
                res[i] = min(res[i], suffix[i]);
            }
        }
    }
    return res;
}

// Maintain position
// Time - O(n)
// Space - O(1)
vector<int> shortestToChar(string s, char c)
{
    int n = s.size();
    vector<int> res(n, INT_MAX);

    int pos = -n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
            pos = i;
        res[i] = min(res[i], i - pos);
    }
    for (int i = pos - 1; i >= 0; i--)
    {
        if (s[i] == c)
            pos = i;
        res[i] = min(res[i], pos - i);
    }
    return res;
}