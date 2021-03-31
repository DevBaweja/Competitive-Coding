#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        ll F[n], C[m];
        for (ll i = 0; i < n; i++)
            cin >> F[i];
        for (ll i = 0; i < m; i++)
            cin >> C[i];

        int count = 0;
        ll i = 0, j = 0;
        bool current = true; // true - football false - cricket
        while (i < n && j < m)
        {
            if (current)
            {
                if (F[i] < C[j])
                    i++;
                if (F[i] > C[j])
                {
                    current = !current;
                    count++;
                }
            }
            else
            {
                if (F[i] > C[j])
                    j++;
                if (F[i] < C[j])
                {
                    current = !current;
                    count++;
                }
            }
        }

        if (i == n && current)
            count++;
        if (j == m && !current)
            count++;

        cout << count << "\n";
    }
    return 0;
}