#include <bits/stdc++.h>
using namespace std;

// Hashing and Visited Used
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();
    if (n1 != n2)
    {
        cout << "false";
        return 0;
    }
    int n = s2.size();
    unordered_map<char, char> m;
    unordered_set<char> used;
    for (int i = 0; i < n; i++)
    {
        if (m.find(s2[i]) == m.end())
        {
            if (used.find(s1[i]) != used.end())
            {
                cout << "false";
                return 0;
            }
            m[s2[i]] = s1[i];
            used.insert(s1[i]);
        }
        if (m[s2[i]] != s1[i])
        {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
    return 0;
}

// Hashing and Encoding
string
getCode(string s)
{
    string t = "#";
    unordered_map<char, int> m;
    int count = 0;
    for (char el : s)
    {
        if (m.find(el) == m.end())
            m[el] = count++;
        t += (m[el] + '#');
    }
    return t;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << (getCode(s1) == getCode(s2) ? "true" : "false");
}