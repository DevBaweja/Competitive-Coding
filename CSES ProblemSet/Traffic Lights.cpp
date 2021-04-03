#include <bits/stdc++.h>
using namespace std;

/*
int main()
{
    int x;
    cin >> x;
    int n;
    cin >> n;

    vector<bool> v(x + 1);
    int passage = x;
    while (n--)
    {
        int p;
        cin >> p;
        v[p] = 1;
        int result = 0, count = 0;
        for (int i = 1; i < x; i++)
        {
            if (v[i])
                count = 0;
            else
            {
                count++;
                result = max(result, count);
            }
        }
        cout << result + 1 << "\n";
    }
}
*/

int main()
{
    int x;
    cin >> x;
    int n;
    cin >> n;

    set<pair<int, pair<int, int>>> s;
    // s.insert(make_pair(1, 10));
    // s.insert(make_pair(3, 10));
    // s.insert(make_pair(2, 12));
    // s.insert(make_pair(2, 10));

    int p;
    cin >> p;
    s.insert(make_pair(p, make_pair(0, p)));
    s.insert(make_pair(x - p, make_pair(p, x)));
    n--;
    auto itr = s.end();
    --itr;
    cout << itr->first << endl;

    while (n--)
    {
        // s.find();
    }
}