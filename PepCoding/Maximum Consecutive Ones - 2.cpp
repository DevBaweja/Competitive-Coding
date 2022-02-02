#include <bits/stdc++.h>
using namespace std;

// Sliding Window
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;
    int res = 0;
    int count = 0;
    int low = 0;

    if (!k)
    {
        for (int i = 0; i < n; i++)
        {
            if (v[i])
            {
                count++;
                res = max(res, count);
            }
            else
                count = 0;
        }
        cout << res << endl;
        return 0;
    }

    for (int high = 0; high < n; high++)
    {
        if (!v[high])
        {
            if (count < k)
                count++;
            else
            {
                while (low < high && count == k)
                {
                    if (!v[low])
                        count--;
                    low++;
                }
                count++;
            }
        }
        res = max(res, high - low + 1);
    }
    cout << res << endl;
    return 0;
}