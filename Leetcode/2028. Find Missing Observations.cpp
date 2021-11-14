#include <bits/stdc++.h>
using namespace std;

vector<int> missingRolls(vector<int> &rolls, int mean, int n)
{
    vector<int> res(n, 1);
    int m = rolls.size();
    int sum = 0;
    for (int el : rolls)
        sum += el;

    int req = mean * (m + n) - sum;
    if (req < n || req > 6 * n)
        return {};
    req -= n;
    int i = 0;

    while (req)
    {
        int mini = min(req, 5);
        res[i] += mini;
        req -= mini;
        i++;
    }
    return res;
}