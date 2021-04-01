#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> res;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        res.insert(x);
    }

    cout << res.size() << endl;
    return 0;
}