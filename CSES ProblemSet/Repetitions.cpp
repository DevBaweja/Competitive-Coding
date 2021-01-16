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