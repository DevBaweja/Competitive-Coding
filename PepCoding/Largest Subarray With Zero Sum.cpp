#include <bits/stdc++.h>
using namespace std;

// Prefix Sum with Hashing
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int sum = 0;
    unordered_map<int, int> m;
    m[sum] = -1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (m.find(sum) != m.end())
            res = max(res, i - m[sum]);
        else
            m[sum] = i;
    }
    cout << res;
    return 0;
}