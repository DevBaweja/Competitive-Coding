#include <bits/stdc++.h>
using namespace std;

bool isPalindromic(string &str, int left, int right)
{
    // string k(str.begin()+left, str.begin()+right+1);
    // string r(k.begin(), k.end());
    // reverse(r.begin(), r.end());
    // return k==r;
    while (left < right)
        if (str[left++] != str[right--])
            return false;
    return true;
}

int palindromicPartitionUtil(string &str, int left, int right, vector<vector<int>> &dp)
{
    if (left >= right)
        return 0;
    if (isPalindromic(str, left, right))
        return 0;
    if (dp[left][right] != -1)
        return dp[left][right];
    int mini = INT_MAX;
    for (int k = left; k < right; k++)
    {
        int res = palindromicPartitionUtil(str, left, k, dp) +
                  palindromicPartitionUtil(str, k + 1, right, dp) +
                  1;

        mini = min(mini, res);
    }

    return dp[left][right] = mini;
}
int palindromicPartition(string str)
{
    int n = str.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return palindromicPartitionUtil(str, 0, n - 1, dp);
}

int main()
{
    string str = "ababbbabbababa";
    cout << palindromicPartition(str);
    return 0;
}