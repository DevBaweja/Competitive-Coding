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

// Revise
bool isSafe(int x, int y, int n)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int minStepToReachTarget(vector<int> &k, vector<int> &t, int n)
{

    queue<pair<int, pair<int, int>>> q;
    k[0]--;
    k[1]--;
    t[0]--;
    t[1]--;
    q.push({0, {k[0], k[1]}});

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vis[k[0]][k[1]] = true;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int step = p.first;
            int curx = p.second.first;
            int cury = p.second.second;
            if (curx == t[0] && cury == t[1])
                return step;
            int size = 8;
            vector<int> dirx{1, 2, 2, 1, -1, -2, -2, -1};
            vector<int> diry{2, 1, -1, -2, -2, -1, 1, 2};
            for (int k = 0; k < size; k++)
            {
                int nextx = curx + dirx[k];
                int nexty = cury + diry[k];
                if (isSafe(nextx, nexty, n) && !vis[nextx][nexty])
                {
                    vis[nextx][nexty] = true;
                    q.push({step + 1, {nextx, nexty}});
                }
            }
        }
    }
    return -1;
}