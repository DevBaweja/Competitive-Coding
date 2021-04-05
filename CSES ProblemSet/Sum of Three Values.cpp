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

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++)
                if (A[i] + A[j] + A[k] == x)
                {
                    cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
                    return 0;
                }
    cout << "IMPOSSIBLE" << endl;
}
*/

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
    B[2] = 1;
    sort(B.begin(), B.end());

    do
    {
        int sum = 0;
        pair<int, pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            if (B[i])
            {
                if (!p.first)
                    p.first = i + 1;
                else if (!p.second.first)
                    p.second.first = i + 1;
                else
                    p.second.second = i + 1;
                sum += A[i];
            }
        }
        if (sum == x)
        {
            cout << p.first << " " << p.second.first << " " << p.second.second << endl;
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

    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < n; i++)
    {
        int rem = x - A[i].first;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            if (A[j].first + A[k].first == rem)
            {
                cout << A[i].second + 1 << " " << A[j].second + 1 << " " << A[k].second + 1 << endl;
                return 0;
            }
            if (A[j].first + A[k].first < rem)
                j++;
            else
                k--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}