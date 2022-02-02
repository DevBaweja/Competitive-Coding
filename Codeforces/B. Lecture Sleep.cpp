#include <bits/stdc++.h>
using namespace std;

// Sliding Window
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> v(n);
    vector<int> f(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
        cin >> f[i];

    int cur = 0;
    for (int i = 0; i < n; i++)
        if (f[i])
            cur += v[i];
    int res = cur;

    for (int i = 0; i < k; i++)
        if (!f[i])
        {
            cur += v[i];
            res = max(res, cur);
        }

    for (int i = k; i < n; i++)
    {
        if (!f[i - k])
            cur -= v[i - k];
        if (!f[i])
            cur += v[i];
        res = max(res, cur);
    }

    cout << res << endl;
    return 0;
}