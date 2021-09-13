#include <bits/stdc++.h>
using namespace std;

int maxCost(vector<vector<int>> &grid, int n, int m)
{
    for (int j = m - 2; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            int t = i != 0 ? grid[i - 1][j + 1] : 0;
            int b = i != n - 1 ? grid[i + 1][j + 1] : 0;
            grid[i][j] += max({t, grid[i][j + 1], b});
        }
    }

    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, grid[i][0]);
    return maxi;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    cout << maxCost(grid, n, m) << endl;
}
