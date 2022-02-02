#include <bits/stdc++.h>
using namespace std;

// Prefix and Suffix Sum
// Middle Element Approach
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<int> prefix(n, 0);
    prefix[0] = v[0];
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i])
        {
            prefix[i] = prefix[i - 1] + v[i];
            res = max(res, prefix[i]);
        }
    }
    vector<int> suffix(n, 0);
    suffix[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i])
        {
            suffix[i] = suffix[i + 1] + v[i];
            res = max(res, suffix[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!v[i])
        {
            int left = i != 0 ? prefix[i - 1] : 0;
            int right = i != n - 1 ? suffix[i + 1] : 0;
            res = max(res, left + right + 1);
        }
    }
    cout << res << endl;
    return 0;
}

// Sliding Window
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = 0;
    bool flag = false;
    int low = 0;
    for (int high = 0; high < n; high++)
    {
        if (!v[high])
        {
            if (!flag)
                flag = true;
            else
            {
                while (low < high && flag)
                {
                    if (!v[low])
                        flag = false;
                    low++;
                }
                flag = true;
            }
        }
        res = max(res, high - low + 1);
    }
    cout << res << endl;
    return 0;
}