#include <bits/stdc++.h>
using namespace std;

// Reverse
bool isPalindromeUtil(string s)
{
    int n = s.size();
    if (n == 0 || n == 1)
        return true;
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

bool isPalindrome(string s)
{
    string res = "";
    for (char el : s)
    {
        if (el >= 'A' && el <= 'Z')
            el = el + 32;
        if (el >= 'a' && el <= 'z')
            res += el;
        if (el >= '0' && el <= '9')
            res += el;
    }
    return isPalindromeUtil(res);
}

// In place Reverse
pair<bool, char> getReq(char el)
{
    if ((el >= 'a' && el <= 'z') || (el >= '0' && el <= '9'))
        return {true, el};
    if (el >= 'A' && el <= 'Z')
        return {true, el + 32};
    return {false, 'a'};
}
bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (!getReq(s[l]).first)
            l++;
        else if (!getReq(s[r]).first)
            r--;
        else if (getReq(s[l++]).second != getReq(s[r--]).second)
            return false;
    }
    return true;
}