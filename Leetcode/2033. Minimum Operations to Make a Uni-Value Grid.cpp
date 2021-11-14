#include <bits/stdc++.h>
using namespace std;

// Median
int minOperations(vector<vector<int>> &grid, int avail)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    vector<int> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            v.push_back(grid[i][j]);

    sort(v.begin(), v.end());

    int k = v.size();
    int mid = v[k / 2];

    int count = 0;
    for (int i = 0; i < k; i++)
    {
        int diff = abs(v[i] - mid);
        if (diff % avail != 0)
            return -1;
        count += diff / avail;
    }
    return count;
}