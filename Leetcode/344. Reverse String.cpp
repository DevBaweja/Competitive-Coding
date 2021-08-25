#include <bits/stdc++.h>
using namespace std;

void reverseString(vector<char> &s)
{
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r)
        swap(s[l++], s[r--]);
}