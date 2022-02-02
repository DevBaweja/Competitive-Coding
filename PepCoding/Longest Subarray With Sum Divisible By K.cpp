#include <bits/stdc++.h>
using namespace std;

// Prefix Sum and Hashing
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;

    int sum = 0;
    unordered_map<int, int> m;
    m[sum] = -1;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        int rem = sum % k;
        if (rem < 0)
            rem += k;
        if (m.find(rem) != m.end())
            maxi = max(maxi, i - m[rem]);
        else
            m[rem] = i;
    }
    cout << maxi;
    return 0;
}