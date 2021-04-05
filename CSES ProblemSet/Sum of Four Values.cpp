#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    map<int, pair<int, int>> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int num = A[i] + A[j];
            if (m.find(x - num) != m.end())
            {
                cout << i + 1 << " " << j + 1 << " " << m[x - num].first + 1 << " " << m[x - num].second + 1 << endl;
                return 0;
            }
        }

        for (int j = 0; j < i; j++)
            m[A[i] + A[j]] = make_pair(i, j);
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}