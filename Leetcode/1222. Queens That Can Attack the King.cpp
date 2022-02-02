#include <bits/stdc++.h>
using namespace std;

// Doesn't work
bool queensAttacktheKingUtil(vector<int> &el, vector<int> &king, int n)
{
    if (el[0] == king[0] || el[1] == king[1])
        return true;

    int curx, cury;
    curx = el[0];
    cury = el[1];

    for (int i = -n; i >= n; i++)
    {
        if (curx + i == king[0] && cury + i == king[1])
            return true;
        if (curx + i == king[0] && cury - i == king[1])
            return true;
        if (curx - i == king[0] && cury + i == king[1])
            return true;
        if (curx - i == king[0] && cury - i == king[1])
            return true;
    }
    return false;
}

vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
{
    int n = 8;
    vector<vector<int>> res;
    for (vector<int> el : queens)
    {
        if (queensAttacktheKingUtil(el, king, n))
            res.push_back(el);
    }
    return res;
}