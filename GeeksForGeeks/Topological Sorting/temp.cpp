#include <bits/stdc++.h>
using namespace std;

int booleanParenthesization(string s1, string s2, int n)
{
    vector<vector<int>> dpT(n, vector<int>(n, 0));
    vector<vector<int>> dpF(n, vector<int>(n, 0));

    for (int g = 0, g < n; g++)
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
                else
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
                    else if (op == '|')
                    {
                        resT += lt * rt + lt * rf + lf * rt;
                        resF += lf * rf;
                    }
                    else if (op == '^')
                    {
                        resT += lt * rf + lf * rt;
                        resF += lt * rt + lf * rf;
                    }
                }
                dpT[i][j] = resT;
                dpF[i][j] = resF;
            }
        }
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    cout << booleanParenthesization(s1, s2, n);
    return 0;
}