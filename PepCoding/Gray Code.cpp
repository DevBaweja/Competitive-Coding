#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n)
{
    if (!n)
        return {0};
    vector<int> subres = grayCode(n - 1);
    vector<int> res;
    for (int el : subres)
    {
        int newel = el << 1;
        res.push_back(newel);
        res.push_back(newel + 1);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> res = grayCode(n);
    int k = res.size();
    cout << "[";
    for (int i = 0; i < k; i++)
    {
        cout << res[i];
        if (i != k - 1)
            cout << ", ";
    }
    cout << "]";
}