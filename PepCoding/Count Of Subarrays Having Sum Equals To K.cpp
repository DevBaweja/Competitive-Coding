#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;

    int sum = 0, count = 0;
    unordered_map<int, int> m;
    m[sum] = 1;
    for (int el : v)
    {
        sum += el;
        if (m.find(sum - k) != m.end())
            count += m[sum - k];
        m[sum]++;
    }
    cout << count;
    return 0;
}