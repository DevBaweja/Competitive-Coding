#include <bits/stdc++.h>
using namespace std;

int fact(int x)
{
    if (x == 0 || x == 1)
        return 1;
    return x * fact(x - 1);
}

string getPermutation(int n, int k)
{
    string res = "";
    vector<int> digit(n);
    for (int i = 1; i <= n; i++)
        digit[i - 1] = i;

    for (int i = n; i >= 1; i--)
    {
        int range = (k / fact(i - 1));
        // boundary
        if (k % fact(i - 1) == 0)
            range--;
        res += (digit[range]);
        digit.erase(digit.begin() + range);
        k -= fact(i - 1) * range;
    }
    return res;
}