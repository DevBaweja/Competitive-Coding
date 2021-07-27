#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s;
        cin >> s;
        int m = 1, c = 1, v = 1;
        while (s > m)
        {
            v += 2;
            m += v;
            c++;
        }
        cout << c;
    }
    return 0;
}