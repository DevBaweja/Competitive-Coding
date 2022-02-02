#include <bits/stdc++.h>
using namespace std;

// Brute Force
char findTheDifference(string s, string t)
{
    unordered_map<char, int> m1, m2;
    for (char el : s)
        m1[el]++;
    for (char el : t)
        m2[el]++;

    for (pair<char, int> p : m2)
    {
        if (m1[p.first] != p.second)
            return p.first;
    }
    return 'a';
}

// Hashing
char findTheDifference(string s, string t)
{
    unordered_map<char, int> m1;
    for (char el : s)
        m1[el]++;
    for (char el : t)
        m1[el]--;

    for (pair<char, int> p : m1)
    {
        if (p.second)
            return p.first;
    }
    return 'a';
}

char findTheDifference(string s, string t)
{
    int size = 26;
    vector<int> count(size, 0);

    for (char el : s)
        count[el - 'a']++;
    for (char el : t)
        count[el - 'a']--;

    for (int i = 0; i < size; i++)
        if (count[i])
            return i + 'a';

    return 'a';
}

// XOR
char findTheDifference(string s, string t)
{
    int x = 0;
    for (char el : s)
        x ^= el - 'a';
    for (char el : t)
        x ^= el - 'a';

    return x + 'a';
}

char findTheDifference(string s, string t)
{
    int n = s.size();
    int x = t[0] - 'a';
    for (int i = 0; i < n; i++)
    {
        x ^= s[i] - 'a';
        x ^= t[i + 1] - 'a';
    }
    return x + 'a';
}