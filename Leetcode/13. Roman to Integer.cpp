#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int n = s.size();
    int res = 0;
    int i = n - 1;
    unordered_map<char, int> m{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};
    while (i >= 0)
    {
        if (i != 0 && m[s[i]] > m[s[i - 1]])
        {
            res += m[s[i]] - m[s[i - 1]];
            i -= 2;
        }
        else
            res += m[s[i--]];
    }
    return res;
}