#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sb, st;
pair<ll, int> med = {-1, -1};
set<pair<ll, int>> tp, bt;

void fix()
{
    int m = 1 + tp.size() + bt.size();
    if (bt.size() < (m - 1) / 2)
    {
        bt.insert(med);
        sb += med.first;
        med = *tp.begin();
        tp.erase(med);
        st -= med.first;
    }
    if (bt.size() > (m - 1) / 2)
    {
        tp.insert(med);
        st += med.first;
        med = *--bt.end();
        bt.erase(med);
        sb -= med.first;
    }
}

void add(pair<ll, int> temp)
{
    if (med.first == -1)
    {
        med = temp;
        return;
    }
    if (temp < med)
    {
        bt.insert(temp);
        sb += temp.first;
    }
    else
    {
        tp.insert(temp);
        st += temp.first;
    }

    fix();
}

void remove(pair<ll, int> temp)
{
    if (temp == med)
    {
        med = *tp.begin();
        tp.erase(med);
        st -= med.first;
    }
    else if (temp < med)
    {
        bt.erase(temp);
        sb -= temp.first;
    }
    else
    {
        tp.erase(temp);
        st -= temp.first;
    }
    fix();
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            cout << 0 << " ";
        return 0;
    }

    for (int i = 0; i < k - 1; i++)
        add({A[i], i});

    for (int i = k - 1; i < n; i++)
    {
        add({A[i], i});
        cout << st - med.first * (ll)tp.size() + med.first * (ll)bt.size() - sb << " ";
        remove({A[i - k + 1], i - k + 1});
    }
}