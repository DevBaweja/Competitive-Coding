#include <bits/stdc++.h>
using namespace std;

// Hashing and Sliding Window
int main()
{
    string str;
    cin >> str;
    int n = str.size();
    if (!n)
        return n;
    unordered_map<char, int> m;
    int count = 0;
    int res = 1;

    int low = 0;
    for (int high = 0; high < n; high++)
    {
        char acquire = str[high];
        if (m[acquire] == 1)
            count++;
        m[acquire]++;

        if (!count)
            res = max(res, high - low + 1);

        while (low <= high && count)
        {
            char release = str[low];
            m[release]--;
            if (m[release] == 1)
                count--;
            low++;
        }
    }
    cout << res;
}