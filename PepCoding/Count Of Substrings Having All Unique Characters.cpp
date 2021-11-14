#include <bits/stdc++.h>
using namespace std;

// Sliding Window
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> m;
    int low = 0, high = 0;
    int count = 0;
    int res = 0;
    while (high < n)
    {
        char acquire = s[high];
        if (m[acquire] == 1)
            count++;
        m[acquire]++;

        if (!count)
            res += high - low + 1;

        while (low < high && count)
        {
            char release = s[low];
            m[release]--;
            if (m[release] == 1)
                count--;
            if (!count)
                res += high - low;
            low++;
        }
        high++;
    }
    cout << res << endl;
    return 0;
}