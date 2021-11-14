#include <bits/stdc++.h>
using namespace std;

vector<int> findOriginalArray(vector<int> &v)
{
    int n = v.size();
    if (n & 1)
        return {};

    unordered_map<int, int> m;
    int zero = 0;
    int isZero = 0;
    for (int el : v)
    {
        m[el]++;
        zero += !el;
        isZero |= el;
    }

    if (!isZero && zero == n)
        return vector<int>(n / 2, 0);

    vector<int> ans;
    if (zero & 1)
        return {};
    else
    {
        int size = zero / 2;
        while (size--)
            ans.push_back(0);
    }

    sort(v.begin(), v.end());
    int index = zero;
    while (index < n)
    {
        int el = v[index];
        if (m[el] && m[2 * el])
        {
            ans.push_back(el);
            m[el]--;
            m[2 * el]--;
        }
        index++;
    }

    if (ans.size() != n / 2)
        return {};

    return ans;
}