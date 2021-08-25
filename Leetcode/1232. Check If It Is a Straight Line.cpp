#include <bits/stdc++.h>
using namespace std;

bool checkStraightLine(vector<vector<int>> &coordinates)
{
    int n = coordinates.size();
    if (n <= 2)
        return true;
    vector<int> a = coordinates[0];
    vector<int> b = coordinates[1];
    int p = b[1] - a[1];
    int q = b[0] - a[0];

    for (int i = 2; i < n; i++)
    {
        vector<int> a = coordinates[i - 1];
        vector<int> b = coordinates[i];
        int r = b[1] - a[1];
        int s = b[0] - a[0];
        if (p * s != r * q)
            return 0;
    }
    return 1;
}