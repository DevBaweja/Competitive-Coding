#include <bits/stdc++.h>
using namespace std;

// s = aaabbccd and k = 2
// Sliding Window
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    int low = 0;
    unordered_map<char, int> m;
    int res = 0;
    for (int high = 0; high < n; high++)
    {
        char acquire = s[high];
        m[acquire]++;

        while (m.size() > k)
        {
            char release = s[low++];
            m[release]--;
            if (!m[release])
                m.erase(release);
        }

        res = max(res, high - low + 1);
    }
    cout << res << endl;
    return 0;
}