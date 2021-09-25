#include <bits/stdc++.h>
using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arr, int k)
{
    vector<int> res;
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            res.push_back(arr[i][j]);
    sort(res.begin(), res.end());
    return res;
}
