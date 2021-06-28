#include <bits/stdc++.h>
using namespace std;

int countWaysUtil(string &s, int left, int right, int isTrue, vector<vector<vector<int>>> &dp)
{

    if (left > right)
        return 0;
    if (left == right)
    {
        if (isTrue)
            return s[left] == 'T';
        else
            return s[right] == 'F';
    }
    if (dp[isTrue][left][right] != -1)
        return dp[isTrue][left][right];

    int res = 0;
    int mod = 1e3 + 3;
    for (int k = left + 1; k <= right - 1; k += 2)
    {
        int lt, rt, lf, rf;
        if (dp[1][left][k - 1] != -1)
            lt = dp[1][left][k - 1];
        else
            lt = countWaysUtil(s, left, k - 1, 1, dp);
        if (dp[1][k + 1][right] != -1)
            rt = dp[1][k + 1][right];
        else
            rt = countWaysUtil(s, k + 1, right, 1, dp);
        if (dp[0][left][k - 1] != -1)
            lf = dp[0][left][k - 1];
        else
            lf = countWaysUtil(s, left, k - 1, 0, dp);
        ;
        if (dp[0][k + 1][right] != -1)
            rf = dp[0][k + 1][right];
        else
            rf = countWaysUtil(s, k + 1, right, 0, dp);

        if (s[k] == '&')
        {
            if (isTrue)
                res += lt * rt;
            else
                res += lt * rf + lf * rt + lf * rf;
        }
        else if (s[k] == '|')
        {
            if (isTrue)
                res += lt * rt + lt * rf + lf * rt;
            else
                res += lf * rf;
        }
        else if (s[k] == '^')
        {
            if (isTrue)
                res += lt * rf + lf * rt;
            else
                res += lt * rt + lf * rf;
        }
        res %= mod;
    }
    return dp[isTrue][left][right] = res;
}

int countWays(int n, string s)
{
    vector<vector<vector<int>>> dp(2,
                                   vector<vector<int>>(n + 1,
                                                       vector<int>(n + 1,
                                                                   -1)));

    return countWaysUtil(s, 0, n - 1, 1, dp);
}

int main()
{
    string s = "T|T&F^T";
    int n = 7;
    cout << countWays(n, s);
    return 0;
}