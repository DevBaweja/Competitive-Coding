#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        char v[n];
        int sub = 0, result = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == '*')
            {
                sub++;
                result = max(result, sub);
            }
            else
                sub = 0;
        }
        if (result >= k)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}