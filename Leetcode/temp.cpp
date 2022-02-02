#include <bits/stdc++.h>
using namespace std;

bool isValid(int n)
{
    int prev = n & 1;
    n = n >> 1;
    while (n)
    {
        int cur = n & 1;
        n = n >> 1;
        if (!prev && !cur)
            return false;
        prev = cur;
    }
    return true;
}

int helper(int n)
{
    for (int el = n; el >= 0; el--)
        if (isValid(el))
            return el;
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << helper(n) << endl;
    }
    return 0;
}