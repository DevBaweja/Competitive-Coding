#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        n--;
        m--;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        int i = 0, j = 0;
        int x = 1, y = 1;
        int cost = 0;
        while (i < n && j < m)
        {
            if (a[i] > b[j])
            {
                cost += a[i++] * y;
                x++;
            }
            else
            {
                cost += b[j++] * x;
                y++;
            }
        }
        while (i < n)
            cost += a[i++] * y;
        while (j < m)
            cost += b[j++] * x;

        cout << cost << endl;
    }
    return 0;
}