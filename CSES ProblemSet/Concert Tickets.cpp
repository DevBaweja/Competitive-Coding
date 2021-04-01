#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> H(n), T(m);
    for (int i = 0; i < n; i++)
        cin >> H[i];
    for (int i = 0; i < m; i++)
        cin >> T[i];

    sort(H.begin(), H.end());


    vector<int> res(m, -1);
    for (int k = 0; k < m; k++)
    {

        int i = 0;
        while (H[i] <= T[k] && i < n)
            i++;
        if (i == 0)
            continue;
        res[k] = H[i - 1];
        H.erase(H.begin() + i - 1);
        n--;
        if (n == 0)
            break;
    }

    for (int i = 0; i < m; i++)
        cout << res[i] << " ";
    return 0;
}
*/
// Time - O(m*n)
// Space - O(1)

/*
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> H(n), T(m);
    for (int i = 0; i < n; i++)
        cin >> H[i];
    for (int i = 0; i < m; i++)
        cin >> T[i];

    vector<int> res(m, -1);

    set<array<int, 2>> s;
    for (int i = 0; i < n; i++)
        s.insert({H[i], i});

    for (int i = 0; i < m; i++)
    {
        auto itr = s.lower_bound({T[i] + 1, 0});
        if (itr != s.begin())
        {
            --itr;
            res[i] = (*itr)[0];
            s.erase(itr);
        }
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}
*/
// Time - O(m*log(n))
// Space - O(n)

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> H(n), T(m);
    for (int i = 0; i < n; i++)
        cin >> H[i];
    for (int i = 0; i < m; i++)
        cin >> T[i];

    vector<int> res(m, -1);

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
        s.insert(make_pair(H[i], i));

    for (int i = 0; i < m; i++)
    {
        auto itr = s.lower_bound(make_pair(T[i] + 1, 0));
        if (itr != s.begin())
        {
            --itr;
            res[i] = itr->first;
            s.erase(itr);
        }
    }
    for (int i = 0; i < m; i++)
        cout << res[i] << "\n";
}