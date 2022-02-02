#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int alpha = 26;
    unordered_map<string, vector<string>> m;
    for (string el : s)
    {
        string t = "#";
        if (el.size() != 1)
        {
            for (int i = 1; i < el.size(); i++)
            {
                int diff = el[i] - el[i - 1];
                if (diff < 0)
                    diff += alpha;
                // t += (diff + 'a');
                t += (diff + '#');
            }
        }
        m[t].push_back(el);
    }

    for (pair<string, vector<string>> p : m)
    {
        for (string el : p.second)
            cout << el << " ";
        cout << endl;
    }
    return 0;
}