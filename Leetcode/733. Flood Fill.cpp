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

// DFS
bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void floodFillUtil(vector<vector<int>> &image, int curx, int cury, int newColor, int oldColor, int n, int m)
{
    image[curx][cury] = newColor;

    vector<int> dirx{0, 1, 0, -1};
    vector<int> diry{1, 0, -1, 0};
    int size = 4;
    for (int k = 0; k < size; k++)
    {
        int nextx = curx + dirx[k];
        int nexty = cury + diry[k];
        if (isSafe(nextx, nexty, n, m) && image[nextx][nexty] == oldColor)
            floodFillUtil(image, nextx, nexty, newColor, oldColor, n, m);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();
    if (image[sr][sc] == newColor)
        return image;
    floodFillUtil(image, sr, sc, newColor, image[sr][sc], n, m);
    return image;
}

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int n = image.size();
    int m = image[0].size();

    int oldColor = image[sr][sc];
    if (oldColor == newColor)
        return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = newColor;
    while (!q.empty())
    {
        int count = q.size();
        while (count--)
        {
            pair<int, int> p = q.front();
            q.pop();
            int curx = p.first;
            int cury = p.second;
            vector<int> dirx{1, 0, -1, 0};
            vector<int> diry{0, 1, 0, -1};
            int size = 4;
            for (int k = 0; k < size; k++)
            {
                int nextx = curx + dirx[k];
                int nexty = cury + diry[k];
                if (isSafe(nextx, nexty, n, m) && image[nextx][nexty] == oldColor)
                {
                    q.push({nextx, nexty});
                    image[nextx][nexty] = newColor;
                }
            }
        }
    }
    return image;
}