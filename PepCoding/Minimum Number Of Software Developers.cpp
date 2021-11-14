#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> s(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        mp[s[i]] = i;
    }

    int m;
    cin >> m;
    vector<vector<int>> a(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            string k;
            cin >> k;
            a[i][mp[k]] = 1;
        }
    }

    vector<int> ans;
    int mini = INT_MAX;
    for (int mask = 0; mask < pow(2, m); mask++)
    {
        vector<int> binary(m, 0);
        int index = 0;
        int temp = mask;
        while (temp)
        {
            binary[index++] = temp & 1;
            temp >>= 1;
        }
        reverse(binary.begin(), binary.end());

        vector<int> vis(n, false);

        int count = 0, total = 0;
        vector<int> res;
        for (int i = 0; i < m; i++)
        {
            if (binary[i])
            {
                total++;
                res.push_back(i);
                for (int j = 0; j < n; j++)
                {
                    if (!vis[j] && a[i][j])
                    {
                        vis[j] = true;
                        count++;
                    }
                }
            }
        }
        if (count == n && total < mini)
        {
            mini = total;
            ans = res;
        }
    }

    int maxi = ans.size();
    for (int i = 0; i < maxi; i++)
    {
        if (!i)
            cout << "[";
        if (i != maxi - 1)
            cout << ans[i] << ", ";
        else
            cout << ans[i] << "]";
    }
    return 0;
}