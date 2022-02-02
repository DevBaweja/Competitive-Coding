#include <bits/stdc++.h>
using namespace std;

// Hashing Indexes and Occuerence
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    unordered_map<int, vector<int>> mv;
    unordered_map<int, int> mi;
    for (int i = 0; i < n; i++)
        mv[b[i]].push_back(i);

    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[i] = mv[a[i]][mi[a[i]]++];
    for (int el : res)
        cout << el << " ";
}