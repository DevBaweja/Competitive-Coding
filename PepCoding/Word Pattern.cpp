#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    unordered_set<string> k;
    unordered_map<char, string> m;
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        if (m.find(s[i]) == m.end())
        {
            if (k.find(v[i]) != k.end())
            {
                ans = false;
                break;
            }
            m[s[i]] = v[i];
            k.insert(v[i]);
        }
        if (m[s[i]] != v[i])
        {
            ans = false;
            break;
        }
    }

    cout << (ans ? "true" : "false");
    return 0;
}