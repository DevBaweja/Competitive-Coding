#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX, maxi = INT_MIN;
        unordered_set<int> s;
        for (int j = i; j < n; j++)
        {
            mini = min(mini, v[j]);
            maxi = max(maxi, v[j]);
            s.insert(v[j]);
            int cur = j - i;
            if (cur != s.size() - 1)
                break;
            if (cur == maxi - mini)
                res = max(res, cur + 1);
        }
    }
    cout << res;
    return 0;
}