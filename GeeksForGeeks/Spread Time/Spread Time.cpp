#include <bits/stdc++.h>
using namespace std;

bool isSafe(int x, int y, int n, int m)
{
    return (x >= 0 && y >= 0 && x < n && y < m);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!mat[i][j])
                    q.push(make_pair(make_pair(i, j), 0));
        int mt = 0;
        while (!q.empty())
        {
            pair<pair<int, int>, int> temp = q.front();
            q.pop();
            pair<int, int> p = temp.first;
            int i = p.first;
            int j = p.second;
            int t = temp.second;
            mt = max(mt, t);

            vector<int> xdir{0, 0, 1, -1};
            vector<int> ydir{-1, 1, 0, 0};

            int len = 4;
            for (int k = 0; k < len; k++)
            {
                int x = i + xdir[k];
                int y = j + ydir[k];
                if (isSafe(x, y, n, m) && mat[x][y])
                {
                    q.push({{x, y}, t + 1});
                    mat[x][y] = 0;
                }
            }
        }
        cout << mt << "\n";
    }
    return 0;
}