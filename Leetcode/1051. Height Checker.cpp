#include <bits/stdc++.h>
using namespace std;

int heightChecker(vector<int> &height)
{
    int n = height.size();
    vector<int> expect = height;
    sort(expect.begin(), expect.end());
    int count = 0;
    for (int i = 0; i < n; i++)
        count += height[i] != expect[i];
    return count;
}