#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, int> med = {-1, -1};
set<pair<ll, int>> tp, bt;

void fix()
{
    int m = 1 + tp.size() + bt.size();
    if (bt.size() < (m - 1) / 2)
    {
        bt.insert(med);
        med = *tp.begin();
        tp.erase(med);
    }
    if (bt.size() > (m - 1) / 2)
    {
        tp.insert(med);
        med = *--bt.end();
        bt.erase(med);
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
        bt.insert(temp);
    else
        tp.insert(temp);

    fix();
}

void remove(pair<ll, int> temp)
{
    if (temp == med)
    {
        med = *tp.begin();
        tp.erase(med);
    }
    else if (temp < med)
        bt.erase(temp);
    else
        tp.erase(temp);
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
            cout << A[i] << " ";
        return 0;
    }

    for (int i = 0; i < k - 1; i++)
        add({A[i], i});

    for (int i = k - 1; i < n; i++)
    {
        add({A[i], i});
        cout << med.first << " ";
        remove({A[i - k + 1], i - k + 1});
    }
}