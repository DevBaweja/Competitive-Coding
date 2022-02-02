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
    m[sum] = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        int rem = sum % k;
        if (rem < 0)
            rem += k;
        if (m.find(rem) != m.end())
            count += m[rem];
        m[rem]++;
    }
    cout << count;
    return 0;
}