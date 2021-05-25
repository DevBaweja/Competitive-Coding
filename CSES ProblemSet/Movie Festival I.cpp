#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(b, a);
    }

    sort(v.begin(), v.end());

    int result = 0, last = 0;

    for (auto itr = v.begin(); itr != v.end(); itr++)
    {
        if (itr->second >= last)
        {
            result++;
            last = itr->first;
        }
    }
    cout << result << endl;
    return 0;
}