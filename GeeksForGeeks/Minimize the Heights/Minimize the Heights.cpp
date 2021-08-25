#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({arr[i] - k, i});
        v.push_back({arr[i] + k, i});
    }
    sort(v.begin(), v.end());

    unordered_map<int, int> m;
    int low = 0;
    int res = INT_MAX;
    for (int high = 0; high < v.size(); high++)
    {
        int hindex = v[high].second;
        m[hindex]++;
        while (m.size() == n)
        {
            res = min(res, v[high].first - v[low].first);
            int lindex = v[low].second;
            m[lindex]--;
            if (m[lindex] == 0)
                m.erase(lindex);
            low++;
        }
    }
    return res;
}