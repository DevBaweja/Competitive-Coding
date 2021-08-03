#include <bits/stdc++.h>
using namespace std;

// Tabular
int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
{

    vector<vector<int>> matrix(n, vector<int>(n, 1));
    for (vector<int> el : mines)
        matrix[el[0]][el[1]] = 0;

    vector<vector<pair<int, int>>> topleft(n, vector<pair<int, int>>(n, {0, 0}));
    vector<vector<pair<int, int>>> bottomright(n, vector<pair<int, int>>(n, {0, 0}));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j])
            {
                topleft[i][j].first = 1;
                topleft[i][j].second = 1;
                bottomright[i][j].first = 1;
                bottomright[i][j].second = 1;
            }

    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j])
            {
                topleft[i][j].first = topleft[i - 1][j].first + 1;
                topleft[i][j].second = topleft[i][j - 1].second + 1;
            }
    for (int i = n - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--)
            if (matrix[i][j])
            {
                bottomright[i][j].first = bottomright[i + 1][j].first + 1;
                bottomright[i][j].second = bottomright[i][j + 1].second + 1;
            }
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res = max(res,
                      min({topleft[i][j].first,
                           topleft[i][j].second,
                           bottomright[i][j].first,
                           bottomright[i][j].second}));
    return res;
}