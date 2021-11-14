#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int k;
    cin >> k;

    vector<int> res;
    unordered_map<int, int> m;
    for (int i = 0; i < k; i++)
        m[v[i]]++;

    res.push_back(m.size());

    for (int i = k; i < n; i++)
    {
        m[v[i]]++;
        m[v[i - k]]--;
        if (!m[v[i - k]])
            m.erase(v[i - k]);
        res.push_back(m.size());
    }

    for (int el : res)
        cout << el << " ";
    return 0;
}