#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll maximizeSum(ll a[], int n, int k)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 && k > 0)
        {
            a[i] = -a[i];
            k--;
        }
    }

    ll sum = 0;
    ll mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        mini = min(mini, a[i]);
    }

    if (k & 1)
        sum -= 2 * mini;
    return sum;
}

ll maximizeSum(ll a[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        pq.push(a[i]);

    while (k--)
    {
        int el = pq.top();
        pq.pop();
        el *= -1;
        pq.push(el);
    }
    int sum = 0;
    while (!pq.empty())
    {
        int el = pq.top();
        pq.pop();
        sum += el;
    }
    return sum;
}