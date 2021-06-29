#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        vector<int> res;
        set<pair<int, int>> s;
        for (int i = 0; i < k; i++)
            s.insert({v[i], i});
        for (int i = k; i < n; i++)
        {
            pair<int, int> el = *(s.begin());
            res.push_back(el.first);
            s.erase(s.begin());
            s.insert({v[i], i});
        }
        while (!s.empty())
        {
            pair<int, int> el = *(s.begin());
            res.push_back(el.first);
            s.erase(s.begin());
        }

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}