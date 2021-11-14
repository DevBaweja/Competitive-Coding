#include <bits/stdc++.h>
using namespace std;

// DP and Range Min Max
// Low High
int findMax(vector<int> &arr, int low, int high)
{
    int maxi = INT_MIN;
    for (int i = low; i <= high; i++)
        maxi = max(maxi, arr[i]);
    return maxi;
}
int mctFromLeafValuesUtil(vector<int> &arr, int low, int high, map<pair<int, int>, int> &m)
{
    if (low == high)
        return 0;

    if (m.find({low, high}) != m.end())
        return m[{low, high}];

    int sum = INT_MAX;
    for (int k = low; k < high; k++)
    {
        int l = mctFromLeafValuesUtil(arr, low, k, m);
        int r = mctFromLeafValuesUtil(arr, k + 1, high, m);
        int maxl = findMax(arr, low, k);
        int maxr = findMax(arr, k + 1, high);
        sum = min(sum, l + r + maxl * maxr);
    }
    return m[{low, high}] = sum;
}

int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    map<pair<int, int>, int> m;
    return mctFromLeafValuesUtil(arr, 0, n - 1, m);
}

// DP
pair<int, int> mctFromLeafValuesUtil(vector<int> &arr, map<vector<int>, pair<int, int>> &m)
{
    int n = arr.size();
    if (arr.size() == 1)
        return {0, arr[0]};

    if (arr.size() == 2)
        return {arr[0] * arr[1], max(arr[0], arr[1])};

    if (m.find(arr) != m.end())
        return m[arr];

    int msum = INT_MAX;
    int mval = INT_MIN;
    for (int i = 1; i <= arr.size() - 1; i++)
    {
        vector<int> vl(arr.begin(), arr.begin() + i);
        pair<int, int> l = mctFromLeafValuesUtil(vl, m);
        vector<int> vr(arr.begin() + i, arr.end());
        pair<int, int> r = mctFromLeafValuesUtil(vr, m);
        int sum = l.first + r.first + l.second * r.second;
        msum = min(msum, sum);
        if (msum == sum)
            mval = max(l.second, r.second);
    }
    return m[arr] = {msum, mval};
}

int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    map<vector<int>, pair<int, int>> m;
    return mctFromLeafValuesUtil(arr, m).first;
}

// Greedy
int mctFromLeafValues(vector<int> &arr)
{
    int n = arr.size();
    if (n == 2)
        return arr[n - 1] * arr[n - 2];
    vector<int> temp(arr.begin(), arr.end());
    int sum = 0;
    while (temp.size() != 1)
    {
        int k = temp.size();
        int mini = 0;
        int minv = temp[mini];
        for (int index = 1; index < k; index++)
        {
            minv = min(minv, temp[index]);
            if (minv == temp[index])
                mini = index;
        }

        int l = (mini != 0) ? temp[mini - 1] * temp[mini] : INT_MAX;
        int r = (mini != k - 1) ? temp[mini] * temp[mini + 1] : INT_MAX;
        sum += min(l, r);

        temp.erase(temp.begin() + mini);
    }

    return sum;
}