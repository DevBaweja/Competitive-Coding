#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &a, int n)
{
    int cur = a[0], res = cur;
    for (int i = 1; i < n; i++)
    {
        cur = max(cur + a[i], a[i]);
        res = max(res, cur);
    }
    return res;
}

int kconcatenation(vector<int> &a, int n, int k)
{
    if (k == 1)
        return kadane(a, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
    vector<int> b(2 * n);
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
        b[i + n] = a[i];
    }
    if (sum > 0)
        return kadane(b, 2 * n) + (k - 2) * sum;
    return kadane(b, 2 * n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << kconcatenation(a, n, k);
    return 0;
}