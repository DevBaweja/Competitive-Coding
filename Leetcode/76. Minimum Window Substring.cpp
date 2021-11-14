#include <bits/stdc++.h>
using namespace std;

string minWindow(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();

    unordered_map<char, int> m1, m2;
    for (char ch : s2)
        m2[ch]++;

    int count = 0;
    int res = INT_MAX;
    int start = -1;
    int low = 0;
    for (int high = 0; high < n1; high++)
    {
        char acquire = s1[high];
        m1[acquire]++;

        if (m2.find(acquire) != m2.end())
        {
            if (m2[acquire] == m1[acquire])
                count++;
        }

        while (count == m2.size())
        {
            res = min(res, high - low);
            if (res == high - low)
                start = low;
            char release = s1[low];

            if (m2.find(release) != m2.end())
            {
                if (m2[release] == m1[release])
                    count--;
            }
            m1[release]--;
            low++;
        }
    }
    if (res == INT_MAX)
        return "";
    return s1.substr(start, res + 1);
}