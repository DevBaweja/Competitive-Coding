#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n)
{
    return (x >= 0 && y >= 0 && x <= n - 1 && y <= n - 1);
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
{
    vector<int> xdir{2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> ydir{1, 2, 2, 1, -1, -2, -2, -1};

    vector<vector<bool>> visit(n, vector<bool>(n, false));
    queue<vector<int>> q;
    int initx = KnightPos[0] - 1;
    int inity = KnightPos[1] - 1;
    q.push({initx, inity, 0});
    visit[initx][inity] = true;
    int finalx = TargetPos[0] - 1;
    int finaly = TargetPos[1] - 1;

    while (!q.empty())
    {
        vector<int> temp = q.front();
        q.pop();
        int curx = temp[0];
        int cury = temp[1];
        int dis = temp[2];

        if (curx == finalx && cury == finaly)
            return dis;

        int pos = 8;
        for (int index = 0; index < pos; index++)
        {
            int nextx = curx + xdir[index];
            int nexty = cury + ydir[index];
            if (isSafe(nextx, nexty, n) && !visit[nextx][nexty])
            {
                visit[nextx][nexty] = true;
                q.push({nextx, nexty, dis + 1});
            }
        }
    }
}