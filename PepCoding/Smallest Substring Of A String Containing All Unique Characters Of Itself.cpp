#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n = str.size();

    unordered_set<char> s;
    for (int el : str)
        s.insert(el);

    unordered_map<char, int> m;
    int low = 0;
    int res = INT_MAX;
    for (int high = 0; high < n; high++)
    {
        int acquire = str[high];
        m[acquire]++;

        while (m.size() == s.size())
        {
            res = min(res, high - low + 1);
            char release = str[low];
            m[release]--;
            if (!m[release])
                m.erase(release);
            low++;
        }
    }
    cout << res << endl;
    return 0;
}