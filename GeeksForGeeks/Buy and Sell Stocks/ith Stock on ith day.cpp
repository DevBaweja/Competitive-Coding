#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, vector<int> price)
{
    int res = 0;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({price[i], i + 1});

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        int buy = min(v[i].second, k / v[i].first);
        res += buy;
        k -= v[i].first * buy;
    }
    return res;
}