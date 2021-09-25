#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int count = 0;
    while (n)
    {
        int rsb = n & -n;
        n -= rsb;
        count++;
    }
    cout << count;
    return 0;
}