#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i].first = b;
        v[i].second.first = a;
        v[i].second.second = i;
    }
    sort(v.begin(), v.end());
    vector<int> res(n);
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        auto itr = s.lower_bound(make_pair(v[i].second.first, 0));
        int index = v[i].second.second;
        if (itr != s.begin())
        {
            --itr;
            res[index] = (*itr).second;
            s.erase(itr);
        }
        else
        {
            res[index] = s.size();
        }
        s.insert(make_pair(v[i].first, res[index]));
    }

    cout << s.size() << "\n";
    for (int i = 0; i < n; i++)
        cout << res[i] + 1 << " ";
}