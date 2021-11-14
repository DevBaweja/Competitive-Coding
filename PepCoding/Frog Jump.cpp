#include <bits/stdc++.h>
using namespace std;

bool jump(vector<int> &arr, int n)
{
    map<int, set<int>> m;
    m[arr[0]].insert(1);

    for (int i = 0; i < n; i++)
    {
        int u = arr[i];
        if (m.find(u) == m.end())
            continue;
        if (u == arr[n - 1])
            return true;

        set<int> list = m[u];
        for (int v : list)
        {
            int p = u + v;
            if (v - 1 > 0)
                m[p].insert(v - 1);
            m[p].insert(v);
            m[p].insert(v + 1);
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << (jump(arr, n) ? "true" : "false");
}