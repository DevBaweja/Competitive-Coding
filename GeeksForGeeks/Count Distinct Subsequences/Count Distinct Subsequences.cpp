#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int j;
        for (j = i; j > 0; j--)
        {
            if (s[i - 1] == s[j - 1])
                break;
        }
        dp[i] = 2 * dp[i - 1];
        if (j)
            dp[i] -= dp[j - 1];
    }
    for (int i = 0; i <= n; i++)
        cout << dp[i] << " ";
    return 0;
}
// Time- O(n^2)
// Space- O(1)

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    map<char, int> m;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1];
        if (m.find(s[i - 1]) != m.end())
        {
            int j = m[s[i - 1]];
            dp[i] -= dp[j - 1];
        }
        m[s[i - 1]] = i - 1;
    }
    cout << dp[n];
    return 0;
}
// Time- O(n)
// Space- O(n)
