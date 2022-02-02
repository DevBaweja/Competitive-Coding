#include <bits/stdc++.h>
using namespace std;

// Sorting
bool canMakeArithmeticProgression(vector<int> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int maxi = arr[n - 1];
    int mini = arr[0];
    int rem = (maxi - mini) % (n - 1);
    if (rem)
        return false;
    int diff = (maxi - mini) / (n - 1);

    int cur = mini + diff;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != cur)
            return false;
        cur += diff;
    }
    return true;
}

// Hashing
bool canMakeArithmeticProgression(vector<int> &arr)
{
    int n = arr.size();
    unordered_set<int> s;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int el : arr)
    {
        mini = min(mini, el);
        maxi = max(maxi, el);
        s.insert(el);
    }

    int rem = (maxi - mini) % (n - 1);
    if (rem)
        return false;
    int diff = (maxi - mini) / (n - 1);

    int cur = mini + diff;
    while (cur != maxi)
    {
        if (s.find(cur) == s.end())
            return false;
        cur += diff;
    }
    return true;
}
