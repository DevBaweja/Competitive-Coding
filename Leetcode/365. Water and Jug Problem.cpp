#include <bits/stdc++.h>
using namespace std;

bool isSafe(int next, int x, int y)
{
    return (next >= 0 && next <= x + y);
}

bool canMeasureWater(int x, int y, int target)
{
    if (x + y < target)
        return false;
    queue<int> q;
    q.push(0);
    vector<bool> vis(x + y, false);
    vis[0] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == target)
            return true;
        vector<int> dir{x, -x, y, -y};
        int size = 4;
        for (int k = 0; k < size; k++)
        {
            int next = cur + dir[k];
            if (isSafe(next, x, y) && !vis[next])
            {
                vis[next] = true;
                q.push(next);
            }
        }
    }
    return false;
}