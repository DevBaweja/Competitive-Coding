#include <bits/stdc++.h>
using namespace std;

bool isScramble(string s1, string s2, map<string, bool> m)
{
    if (s1.length() != s2.length())
        return false;
    if (s1.length() == 0)
        return true;
    if (s1 == s2)
        return true;
    if (s1.length() == 1)
        return false;
    string diff = "_";
    string key = s1 + diff + s2;
    if (m.find(key) != m.end())
        return m[key];
    // Anagrams
    string sc1 = s1, sc2 = s2;
    sort(sc1.begin(), sc1.end());
    sort(sc2.begin(), sc2.end());
    if (sc1 != sc2)
        return m[key] = false;

    int n = s1.length();
    for (int i = 1; i < n; i++)
    {
        if (isScramble(s1.substr(0, i), s2.substr(0, i), m) &&
            isScramble(s1.substr(i, n - i), s2.substr(i, n - i), m))
            return m[key] = true;
        if (isScramble(s1.substr(0, i), s2.substr(n - i, i), m) &&
            isScramble(s1.substr(i, n - i), s2.substr(0, n - i), m))
            return m[key] = true;
    }
    return m[key] = false;
}

int main()
{
    string s1 = "coder";
    string s2 = "ocred";
    map<string, bool> m;
    cout << isScramble(s1, s2, m);
    return 0;
}
