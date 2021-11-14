#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n1 = s1.size(), n2 = s2.size();

    unordered_map<char, int> m1, m2;
    for (char ch : s2)
        m2[ch]++;

    int count = 0;
    int size = INT_MAX;
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
            if (size > high - low)
            {
                size = high - low;
                start = low;
            }
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
    if (size == INT_MAX)
    {
        cout << " ";
        return 0;
    }

    cout << s1.substr(start, size + 1) << endl;
    return 0;
}