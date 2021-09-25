#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int r = n & (~n + 1);
    // int r = n & -n;
    string s = "";
    while (r)
    {
        s = to_string(r & 1) + s;
        r = r >> 1;
    }
    cout << s;
}