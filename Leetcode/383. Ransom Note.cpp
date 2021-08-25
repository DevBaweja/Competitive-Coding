#include <bits/stdc++.h>
using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    int m = magazine.size();
    int n = ransomNote.size();
    if (m < n)
        return 0;
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if (magazine[i] == ransomNote[j])
            j++;
        i++;
    }

    return (j == n);
}

bool canConstruct(string ransomNote, string magazine)
{
    int m = magazine.size();
    int n = ransomNote.size();

    if (m < n)
        return false;
    unordered_map<char, char> m1, m2;
    for (char el : magazine)
        m1[el]++;
    for (char el : ransomNote)
        m2[el]++;
    for (pair<char, char> el : m2)
    {
        if (m1[el.first] < el.second)
            return false;
    }
    return true;
}

bool canConstruct(string ransomNote, string magazine)
{
    int m = magazine.size();
    int n = ransomNote.size();

    if (m < n)
        return false;
    multiset<int> s;
    for (char el : magazine)
        s.insert(el);

    for (char el : ransomNote)
    {
        auto it = s.find(el);
        if (it == s.end())
            return false;
        s.erase(it);
    }
    return true;
}
