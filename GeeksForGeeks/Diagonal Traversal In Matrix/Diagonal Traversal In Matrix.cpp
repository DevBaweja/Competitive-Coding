#include <bits/stdc++.h>
using namespace std;

vector<int> printDigonal(int n, vector<vector<int>> A)
{
    vector<vector<int>> dia(2 * n - 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dia[i + j].push_back(A[i][j]);

    vector<int> res;
    for (int i = 0; i < dia.size(); i++)
        for (int j = 0; j < dia[i].size(); j++)
            res.push_back(dia[i][j]);
    return res;
}