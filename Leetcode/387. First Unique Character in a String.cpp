#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s)
{
    unordered_map<char, int> m;
    for (char el : s)
        m[el]++;
    for (int i = 0; i < s.size(); i++)
    {
        char el = s[i];
        if (m[el] == 1)
            return i;
    }
    return -1;
}