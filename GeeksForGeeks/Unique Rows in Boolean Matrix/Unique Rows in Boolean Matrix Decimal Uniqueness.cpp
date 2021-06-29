#include <bits/stdc++.h>
using namespace std;

int decimal(vector<int> arr, int col)
{
    int sum = 0;
    for (int i = 0; i < col; i++)
        sum = (sum << 1) + arr[i];
    return sum;
}

vector<vector<int>> uniqueRow(vector<vector<int>> M, int row, int col)
{
    vector<vector<int>> res;
    set<int> s;
    for (int i = 0; i < row; i++)
    {
        int dec = decimal(M[i], col);
        if (s.find(dec) == s.end())
        {
            res.push_back(M[i]);
            s.insert(dec);
        }
    }
    return res;
}