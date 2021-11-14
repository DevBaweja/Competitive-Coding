#include <bits/stdc++.h>
using namespace std;

int countGoodSubstrings(string s)
{
    unordered_map<char, int> m;
    int size = 3, count = 0, index = 0;

    while (index < size)
        m[s[index++]]++;
    count += m.size() == size;

    for (int high = size; high < s.size(); high++)
    {
        char acquire = s[high];
        m[acquire]++;
        char release = s[high - size];
        m[release]--;
        if (!m[release])
            m.erase(release);
        count += m.size() == size;
    }
    return count;
}