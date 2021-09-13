#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
void MakeZeros(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<pair<int, int>> zeros;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!matrix[i][j])
                zeros.push_back({i, j});
            dp[i][j] = matrix[i][j];
        }
    }

    for (pair<int, int> el : zeros)
    {
        vector<int> dirx{0, 1, 0, -1};
        vector<int> diry{1, 0, -1, 0};
        int curx = el.first;
        int cury = el.second;

        int size = 4;
        int sum = 0;
        for (int k = 0; k < size; k++)
        {
            int nextx = curx + dirx[k];
            int nexty = cury + diry[k];
            if (isSafe(nextx, nexty, n, m))
            {
                sum += matrix[nextx][nexty];
                dp[nextx][nexty] = 0;
            }
        }
        dp[curx][cury] = sum;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = dp[i][j];
        }
    }
}