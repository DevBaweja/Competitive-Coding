#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n)
{
    return (x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1);
}

bool solveKnightTour(int x, int y, int moves, int n, vector<int> xmove, vector<int> ymove, vector<vector<int>> &res)
{
    if (moves == n * n)
        return true;

    int pos = 8;
    for (int k = 0; k < pos; k++)
    {
        int nextx = x + xmove[k];
        int nexty = y + ymove[k];
        if (isSafe(nextx, nexty, n) && res[nextx][nexty] == -1)
        {
            res[nextx][nexty] = moves;
            if (solveKnightTour(nextx, nexty, moves + 1, n, xmove, ymove, res))
                return true;
            // Backtrack
            res[nextx][nexty] = -1;
        }
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> res(n, vector<int>(n, -1));

    vector<int> xmove{2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> ymove{1, 2, 2, 1, -1, -2, -2, 1};
    res[0][0] = 0;

    if (!solveKnightTour(0, 0, 1, n, xmove, ymove, res))
        return 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
