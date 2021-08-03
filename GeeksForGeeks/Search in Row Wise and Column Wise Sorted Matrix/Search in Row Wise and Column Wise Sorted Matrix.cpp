#include <bits/stdc++.h>
using namespace std;

int matSearch(vector<vector<int>> &mat, int n, int m, int key)
{
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (mat[i][j] == key)
            return 1;
        if (mat[i][j] < key)
            i++;
        else
            j--;
    }
    return 0;
}