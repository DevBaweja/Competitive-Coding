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

    vector<int> rem(k);
    for (int i = 0; i < n; i++)
        rem[v[i] % k]++;

    int low = 1;
    int high = k - 1;
    bool res = true;

    res &= !(rem[0] & 1);

    while (low < high)
    {
        int sum = rem[low++] + rem[high--];
        res &= !(sum & 1);
    }

    if (!k & 1)
        res &= !(rem[k / 2] & 1);

    cout << (res ? "true" : "false");
    return 0;
}