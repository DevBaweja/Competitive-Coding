#include <bits/stdc++.h>
using namespace std;

char slowestKey(vector<int> &releaseTimes, string keysPressed)
{
    int maxi = 0;
    char res;
    int n = releaseTimes.size();
    for (int i = 0; i < n; i++)
    {
        int prev = !i ? 0 : releaseTimes[i - 1];
        int next = releaseTimes[i];
        int cur = next - prev;
        if (cur > maxi)
        {
            res = keysPressed[i];
            maxi = cur;
        }
        if (cur == maxi)
            res = max(res, keysPressed[i]);
    }
    return res;
}