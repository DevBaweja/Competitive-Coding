#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    vector<int> B(n);
    B[0] = 1;
    B[1] = 1;
    sort(B.begin(), B.end());

    do
    {
        int sum = 0;
        pair<int, int> p;
        for (int i = 0; i < n; i++)
        {
            if (B[i])
            {
                if (!p.first)
                    p.first = i + 1;
                else
                    p.second = i + 1;
                sum += A[i];
            }
        }
        if (sum == x)
        {
            cout << p.first << " " << p.second << endl;
            return 0;
        }
    } while (next_permutation(B.begin(), B.end()));

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
*/

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int num = A[i];
        if (m.find(x - num) != m.end())
        {
            cout << m[x - num] + 1 << " " << i + 1 << endl;
            return 0;
        }
        m[num] = i;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}