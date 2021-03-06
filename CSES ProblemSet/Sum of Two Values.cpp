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
            if (A[i] + A[j] == x)
            {
                cout << i + 1 << " " << j + 1 << endl;
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

/*
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
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (A[i].first + A[j].first == x)
        {
            cout << A[i].second + 1 << " " << A[j].second + 1 << endl;
            return 0;
        }
        if (A[i].first + A[j].first < x)
            i++;
        else
            j--;
    }
    cout << "IMPOSSIBLE" << endl;
}