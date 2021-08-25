#include <bits/stdc++.h>
using namespace std;

string nextPalin(string s)
{
    int n = s.size() / 2;

    if (n <= 1)
        return "-1";

    int index = n - 1;
    while (index > 0 && s[index - 1] >= s[index])
        index--;

    if (!index)
        return "-1";

    int el = index;
    for (int k = index; k < n && s[index - 1] < s[k]; k++)
        el = k;

    swap(s[index - 1], s[el]);
    reverse(s.begin() + index, s.begin() + n);

    string res(s.begin(), s.begin() + n);
    string ans = res;
    int k = s.size();
    if (k % 2 != 0)
        ans += s[k / 2];
    reverse(res.begin(), res.end());
    ans += res;
    return ans;
}