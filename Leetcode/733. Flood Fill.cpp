#include <bits/stdc++.h>
using namespace std;

// BFS
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int prevColor = image[sr][sc];
    int n = image.size();
    int m = image[0].size();
    // image, sr, sc, n, m, prevColor, newColor
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;

    vector<int> xdir{-1, 1, 0, 0};
    vector<int> ydir{0, 0, 1, -1};

    while (!q.empty())
    {
        pair<int, int> temp = q.front();
        q.pop();
        int curx = temp.first;
        int cury = temp.second;

        if (image[curx][cury] != prevColor)
            continue;
        if (image[curx][cury] == newColor)
            continue;

        image[curx][cury] = newColor;

        int pos = 4;
        for (int index = 0; index < pos; index++)
        {
            int nextx = curx + xdir[index];
            int nexty = cury + ydir[index];

            if (isSafe(nextx, nexty, n, m) &&
                !visited[nextx][nexty])
            {
                visited[nextx][nexty] = true;
                q.push({nextx, nexty});
            }
        }
    }
    return image;
}
