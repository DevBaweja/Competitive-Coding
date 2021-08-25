#include <bits/stdc++.h>
using namespace std;

bool isPalindromic(string &str, int left, int right)
{
    while (left < right)
        if (str[left++] != str[right--])
            return false;
    return true;
}

int main()
{
    string str;
    cin >> str;
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            else if (g == 1)
            {
                if (str[i] == str[j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else
            {
                if (isPalindromic(str, i, j))
                    dp[i][j] = 0;
                else
                {
                    int mini = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        int l = dp[i][k];
                        int r = dp[k + 1][j];
                        mini = min(mini, l + r + 1);
                    }
                    dp[i][j] = mini;
                }
            }
        }
    }
    cout << dp[0][n - 1];
}