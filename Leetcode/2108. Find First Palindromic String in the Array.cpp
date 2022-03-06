#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.size();
    int l = 0, r = n - 1;
    while (l < r)
        if (s[l++] != s[r--])
            return false;
    return true;
}
string firstPalindrome(vector<string> &words)
{
    for (string word : words)
        if (isPalindrome(word))
            return word;
    return "";
}