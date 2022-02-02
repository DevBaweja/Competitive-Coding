#include <bits/stdc++.h>
using namespace std;

// Hashing and Sorting
int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < n; i++)
    {
        string s = v[i];
        sort(s.begin(), s.end());
        m[s].push_back(v[i]);
    }

    for (pair<string, vector<string>> p : m)
    {
        for (string el : p.second)
            cout << el << " ";
        cout << endl;
    }
}