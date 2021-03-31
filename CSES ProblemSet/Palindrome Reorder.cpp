#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string str;
    cin >> str;
    int n = 26;
    vector<int> count(n);
    for (int i = 0; i < str.length(); i++)
        count[str[i] - 'A']++;

    int odd = 0;
    for (int i = 0; i < n; i++)
        odd += count[i] & 1;

    if (odd > 1)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    string t;
    for (int i = 0; i < n; i++)
    {
        if (count[i] & 1 ^ 1)
            for (int j = 0; j < count[i] / 2; j++)
                t += (char)('A' + i);
    }
    cout << t;

    for (int i = 0; i < n; i++)
    {
        if (count[i] & 1)
            for (int j = 0; j < count[i]; j++)
                cout << (char)('A' + i);
    }

    reverse(t.begin(), t.end());
    cout << t;
}