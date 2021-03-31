#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, int from, int aux, int to, vector<pair<int, int>> &v)
{
    if (n == 1)
    {
        v.push_back(pair<int, int>(from, to));
        return;
    }
    towerOfHanoi(n - 1, from, to, aux, v);
    v.push_back(pair<int, int>(from, to));
    towerOfHanoi(n - 1, aux, from, to, v);
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    towerOfHanoi(n, 1, 2, 3, v);

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << "\n";
}