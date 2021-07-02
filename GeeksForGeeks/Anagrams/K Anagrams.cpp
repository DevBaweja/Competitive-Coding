#include <bits/stdc++.h>
using namespace std;

bool areKAnagrams(string str1, string str2, int k)
{
    vector<int> v(26, 0);
    for (char el : str1)
        v[el - 'a']++;
    for (char el : str2)
        v[el - 'a']--;
    int res = 0;
    for (int i = 0; i < 26; i++)
        res += abs(v[i]);
    return str1.size() == str2.size() && res <= 2 * k;
}