#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Hashing
string fractionToDecimal(ll a, ll b)
{
    string res = "";
    if (!a)
        return "0";
    if (a < 0 ^ b < 0)
        res += '-';
    a = abs(a);
    b = abs(b);
    ll q = a / b;
    ll r = a % b;
    res += to_string(q);
    if (!r)
        return res;

    res += '.';

    unordered_map<ll, int> m;
    m[r] = res.size();
    while (r)
    {
        r *= 10;
        q = r / b;
        r = r % b;
        res += to_string(abs(q));
        if (m.find(r) != m.end())
        {
            string ans = res.substr(0, m[r]) +
                         "(" + res.substr(m[r], res.size() - m[r]) + ")";
            return ans;
        }

        m[r] = res.size();
    }
    return res;
}