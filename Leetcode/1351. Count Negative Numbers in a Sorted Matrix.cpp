#include <bits/stdc++.h>
using namespace std;

// Brute Force
int countNegatives(vector<vector<int>> &grid)
{
    int count = 0;
    for (vector<int> v : grid)
        for (int el : v)
            count += (el < 0);
    return count;
}

// Top Right Algorithm
int countNegatives(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[n - 1].size();

    int x = 0, y = m - 1;

    int c = 0;
    while (x < n)
    {
        while (y >= 0 && grid[x][y] < 0)
            y--;
        c += m - y - 1;
        x++;
    }
    return c;
}