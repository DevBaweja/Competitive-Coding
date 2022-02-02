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

    int sum = 0;
    unordered_map<int, int> m;
    m[sum] = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (v[i] ? 1 : -1);
        if (m.find(sum) != m.end())
            count += m[sum];
        m[sum]++;
    }
    cout << count;
    return 0;
}