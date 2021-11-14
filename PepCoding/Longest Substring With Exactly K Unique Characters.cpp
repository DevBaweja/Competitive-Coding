#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();

    unordered_map<char, int> m;
    int low = 0;
    int res = INT_MIN;

    for (int high = 0; high < n; high++)
    {
        char acquire = s[high];
        m[acquire]++;

        while (low < high && m.size() > k)
        {
            char release = s[low];
            m[release]--;
            if (!m[release])
                m.erase(release);
            low++;
        }
        if (m.size() == k)
            res = max(res, high - low + 1);
    }
    if (res == INT_MIN)
        res = -1;
    cout << res << endl;
}