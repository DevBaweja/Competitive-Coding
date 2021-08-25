#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> m;
    int sum = 0;
    m.insert(0);
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0 || m.find(sum) != m.end())
            return true;
        m.insert(sum);
    }
    return false;
}