#include <bits/stdc++.h>
using namespace std;

int countWays(int len, string s)
{
    string s1 = "";
    string s2 = "";
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
            s1 += s[i];
        else
            s2 += s[i];
    }
    int mod = 1e3 + 3;
    int n = (len + 1) / 2;
    vector<vector<int>> dpT(n, vector<int>(n, 0));
    vector<vector<int>> dpF(n, vector<int>(n, 0));

    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (!g)
            {
                if (s1[i] == 'T')
                {
                    dpT[i][j] = 1;
                    dpF[i][j] = 0;
                }
                if (s1[i] == 'F')
                {
                    dpT[i][j] = 0;
                    dpF[i][j] = 1;
                }
            }
            else
            {
                int resT = 0;
                int resF = 0;
                for (int k = i; k < j; k++)
                {
                    char op = s2[k];
                    int lt = dpT[i][k];
                    int rt = dpT[k + 1][j];
                    int lf = dpF[i][k];
                    int rf = dpF[k + 1][j];
                    if (op == '&')
                    {
                        resT += lt * rt;
                        resF += lt * rf + lf * rt + lf * rf;
                    }
                    if (op == '|')
                    {
                        resT += lt * rt + lt * rf + lf * rt;
                        resF += lf * rf;
                    }
                    if (op == '^')
                    {
                        resT += lt * rf + lf * rt;
                        resF += lt * rt + lf * rf;
                    }
                }
                dpT[i][j] = resT % mod;
                dpF[i][j] = resF % mod;
            }
        }
    }

    return dpT[0][n - 1];
}

int main()
{
    string s = "T|T&F^T";
    int n = 7;
    cout << countWays(n, s);
    return 0;
}