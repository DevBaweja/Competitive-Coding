#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    ll count = 0, result = 1;
    char most = 'A';
    for (char c : s)
    {
        if (c == most)
        {
            count++;
            result = max(result, count);
        }
        else
        {
            most = c;
            count = 1;
        }
    }
    cout << result;
}

int main()
{
    string str;
    cin >> str;

    ll count = 1;
    ll res = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (str[i - 1] == str[i])
            count++;
        else
            count = 1;
        res = max(res, count);
    }
    cout << res;
}
